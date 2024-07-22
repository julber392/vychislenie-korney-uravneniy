section .text
global f1
f1:
	push ebp
	mov ebp, esp
	fld1
	fldl2e
	fdivp
	fld qword[ebp+8]
	fyl2x ;lnb(x)=log2(b)^-1*log2(x)
	mov esp, ebp
	pop ebp
	ret
