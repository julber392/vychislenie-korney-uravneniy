section .rodata
    mt: dq -2.0
    ft: dq 14.0
section .text
global f2
f2:
    push ebp
    mov ebp, esp
    fld qword[ebp+8]
    fld qword[mt]
    fmulp
    fld qword[ft]
    faddp
    mov esp, ebp
    pop ebp
    ret
