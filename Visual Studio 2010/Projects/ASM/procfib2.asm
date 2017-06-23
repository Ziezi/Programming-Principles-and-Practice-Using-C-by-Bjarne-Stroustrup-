; TITLE	Fibonacci numbers (stack version)	PROCFIB2.ASM
; COMMENT
;		Objective: To compute Fibonacci number using the stack for local variables.
;			Input: Requests a positive integer from the user.
;		   Output: Outputs the largest Fibonacci number that is less than or equal to the input number.

section.data
prompt_msg		DB	"Please input a positive number (>1).", 0
output_msg1		DB	"The largest Fibonacci number less than"
				DB	"or equal to", 0
output_msg2		DB	"is", 0

section.text
%include "io.mac"
		.STARTUP
		PutStr	prompt_msg
		GetInt	EDX
		nwln
		call	fibonacci
		PutStr	output_msg1		; print Fibonacci number
		PutInt	EDX
		PutStr	output_msg2
		PutInt	EAX 
done:
		.EXIT
;------------------------------------------------------------------------------------------------------------------------------
; Procedure Fibonacci receives an integer in DX and computes the largest Fibonacci number that is less than the input number.
; The fibonacci number is returned at AX.
;------------------------------------------------------------------------------------------------------------------------------
FIB_LO	%define	WORD PTR [BP-2]	
FIB_HI	%define	WORD PTR [BP-4]
fibonacci:
		enter 4,0		; 4 bytes of of space for local variables, reserved
		push  EBX

		;FIB_LO maintains the smaller of the last two Fibonacci numbers computed
		;FIB_HI maintains the larger of the last two Fibonacci numbers computed
	fib_loop:		
		mov FIB_LO,1	; initialize to the first two Fib numbers(i.e. 1, 1)
		mov FIB_HI,1
		add EBX,EAX
		mov FIB_LO,EAX
		mov FIB_HI,EBX
		cmp	EBX,EDX
		jle	fib_loop	; check if BX <= DX, if true: find next Fib number
		; AX contains the required Fib number
		pop	EBX
		leave			; clears local variable space
		ret
 
