"""Talk to the modded DOSBox-X harness and locate STRONG.EXE's live data segments.

The harness is a patched DOSBox-X (emulator/dosbox-x-mod.exe) that listens on
127.0.0.1:23946 and accepts text commands.  This module needs nothing else:
run dosbox-x-mod.exe with emulator/strong.conf, wait for the game's
"ENTER: use previous configuration" prompt, send ENTER, then use this.

Memory is addressed as guest *linear* addresses (physical), so a
segment:offset pair needs the segment's runtime value, which DOS picks at
load time.  find_dgroup() recovers it from a known string instead of
assuming a fixed base: the two stages of STRONG.EXE (setup and game) load at
different paragraphs, so the delta must be recomputed for each process.
"""
import socket
import time

PORT = 23946
GHIDRA_DGROUP = 0x2410          # Ghidra's segment for DS
UNDEVELOPED = bytes.fromhex('756E646576656C6F706564')   # "undeveloped"
UNDEVELOPED_OFF = 0x1D11        # Ghidra 2410:1d11


class Probe:
    def __init__(self, port=PORT, wait=1.0):
        self.s = socket.create_connection(('127.0.0.1', port), timeout=10)
        self.wait = wait
        time.sleep(0.3)
        try:
            self.s.recv(65536)
        except socket.timeout:
            pass
        self.s.settimeout(10)
        self.dseg = None
        self.delta = None

    def cmd(self, c, wait=None):
        self.s.sendall((c + '\n').encode())
        time.sleep(self.wait if wait is None else wait)
        out = b''
        self.s.settimeout(1.0)
        try:
            while True:
                d = self.s.recv(65536)
                if not d:
                    break
                out += d
        except socket.timeout:
            pass
        self.s.settimeout(10)
        return out.decode(errors='replace')

    def peek(self, lin, n=16):
        """Read up to 64 bytes (the harness caps peek at 64)."""
        n = min(n, 64)
        r = self.cmd('peek %X %u' % (lin, n))
        for line in r.splitlines():
            if line.startswith('DATA'):
                return bytes.fromhex(line[4:].strip().replace(' ', ''))
        return b''

    def read(self, lin, n):
        out = b''
        while len(out) < n:
            chunk = self.peek(lin + len(out), min(64, n - len(out)))
            if not chunk:
                break
            out += chunk
        return out

    def dump(self, lin, n, path):
        r = self.cmd('dump %X %X %s' % (lin, n, path), wait=2.5)
        return 'OK dump' in r

    def find(self, pattern, start=0, end=0x1000000):
        r = self.cmd('find %s %X %X' % (pattern.hex(), start, end), wait=2.0)
        if 'FOUND' in r:
            return int(r.split('FOUND')[1].split()[0], 16)
        return None

    def locate(self):
        """Recover the DGROUP runtime segment from the game's own data."""
        lin_found = self.find(UNDEVELOPED)
        if lin_found is None:
            raise RuntimeError('game not loaded (string not found)')
        self.dseg = (lin_found - UNDEVELOPED_OFF) >> 4
        self.delta = GHIDRA_DGROUP - self.dseg
        return self.dseg

    def addr(self, ghidra_addr):
        """Convert a Ghidra segment:offset address to a guest linear address."""
        if self.delta is None:
            self.locate()
        s, o = ghidra_addr.split(':')
        return ((int(s, 16) - self.delta) << 4) + int(o, 16)


if __name__ == '__main__':
    p = Probe()
    seg = p.locate()
    print('DGROUP runtime segment = %04X (delta %X)' % (seg, p.delta))
    for a in ('195d:26d6', '2410:0958', '1726:0000', '1ef4:0000'):
        print('%-10s -> %08X' % (a, p.addr(a)))
