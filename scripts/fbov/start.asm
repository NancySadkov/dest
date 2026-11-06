.MODEL LARGE
.CODE
EXTRN _main:FAR
PUBLIC _start
_start PROC FAR
    xor ax,ax
    push ax            ; argv.seg
    push ax            ; argv.ofs
    push ax            ; argc
    call far ptr _main
    add sp,6
    mov ax,4c00h
    int 21h
_start ENDP
END _start
