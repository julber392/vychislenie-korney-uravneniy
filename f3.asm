section .rodata
    two: dq 2.0
    six: dq 6.0
section .text
global f3
f3:
    push ebp
    mov ebp, esp
    fld1
    fld qword[two]
    fld qword[ebp+8]
    fsubp
    fdivp
    fld qword[six]
    faddp
    mov esp, ebp
    pop ebp
    ret
