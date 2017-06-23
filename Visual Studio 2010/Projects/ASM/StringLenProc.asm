; TITLE	String Length Procedure		StringLenProc.asm
; COMMENT
;		Objective: To write a procedure to compute string length of a NULL terminated string.
;			Input: String pointer in BX register.
;		   Output: Returns string length in AX.

section.code
PUBLIC StringLen				; the label: StringLen is made: public, thereby available for another modules to call/use
StringLen:
	push	EBX
	sub		EAX,EAX
repeat:
	cmp		BYTE PTR [EBX], 0
	je		done
	inc		EAX
	inc		EBX
	jmp		repeat
done:
	pop		EBX
	ret
 

