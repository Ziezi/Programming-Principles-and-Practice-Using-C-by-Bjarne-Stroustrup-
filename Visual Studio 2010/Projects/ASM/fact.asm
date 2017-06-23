; TITLE	Factorial - Recursive version	fact.asm
; COMMENT
;		Objective: To demonstrate principles of recursion
;			Input: Requests an integer N from the user.
;		   Output: Outputs N!


 
section.data
prompt_msg		DB	"Please enter a positive integer.", 0
output_msg		DB	"The facotorial is: ", 0
error_msg		DB	"Sorry! Not a positive number. Try again.", 0

section.text
%include "io.mac"
		.STARTUP
		PutStr	prompt_msg				

try_again
		GetInt	EBX				; read number into BX
		nwln
		cmp		EBX,0			; test for positive number
		jge		num_ok
		PutStr	error_msg
		nwln
		jmp		try_again

num_ok:
		call	fact

		PutStr	output_msg		; ouput result
		PutInt	EAX
		nwln
done:
		.EXIT
;--------------------------------------------------------------------------------------------
; Procedure fact receives a positive number N in BX register.
; It returns facotial(input positive integer)! in AX register.
;--------------------------------------------------------------------------------------------

fact:	 
		cmp		EBX,1			; if N > 1, recurse
		jg		one_up
		mov		EAX,1			; return 1 for N < 2
		ret

one_up:
		dec		EBL				; recurse with (N-1)
		call	fact
		inc		EBL
		mul		EBL				; AX = AL * BL

		ret