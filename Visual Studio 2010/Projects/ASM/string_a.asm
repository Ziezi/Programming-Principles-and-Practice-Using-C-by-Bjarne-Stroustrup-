; TITLE	String processing, demonstrating global variables	string_c.cpp
; COMMENT
;		Objective: String processing implemented by mix-mode programming, with the use og global variables.
;			Input: Works on the passed global variable: string 
;		   Output: Returns the result to the calling C function.

EXTRN	_string:byte

section.text
PUBLIC	_string_length
_srting_length:
		mov		AX,0				; keeps the character count
		mov		BX,OFFSET _string	; load BX with string address
	repeat:
		cmp		BYTE PTR[BX],0		; compare with NULL character
		jz		done				; if = NULL character => done
		inc		AX					; increment the string legth
		inc		BX					; increment to the next character
		jmp		repeat
	done:
		ret
		end
		
