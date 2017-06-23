;TITLE	String Length Procedure		module2.asm
;COMMENT
;		Objective: To write a procedure to compute string length of a NULL terminated string.
;			Input: String pointer in BX register.
;		   Output: Returns string length in AX.
 
PUBLIC string_length				; the label: string_length is made: public, thereby available for another modules to call/use
string_length:
		; all registers except AX are preserved
		push	SI		; save SI
		mov		SI,BX	; SI := string pointer
	repeat:
		cmp		BYTE PTR [SI], 0	; is it NULL?
		je		done				; of so, done
		inc		SI					; else, move to next character
		jmp		repeat				; and repeat
	done:
		sub		SI,BX				; compute string length as difference in initial address - incremented address (diff. from 0)
		mov		AX,SI				; return string length in AX
		pop		SI					; restore SI
		ret
				; no label after END, as the execution begins in another procedure