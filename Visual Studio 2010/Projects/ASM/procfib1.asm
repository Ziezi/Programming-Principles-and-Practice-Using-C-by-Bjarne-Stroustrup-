; TITLE	Fibonacci Numbers (register version)	procfib1.asm
; COMMENT
;		Objective: To compute Fibonacci number using register for local variables.
;			Input: Requests a positive integer from the user.
;		   Output: Outputs the largest Fibonacci number that is less than or equal to the input number.

 
section.data
prompt_msg		DB	"Please input a positive number (>1). ", 0
output_msg1		DB	"The largest Fibonacci number less than"
				DB	"or equal to", 0
output_msg2		DB	"is", 0 

section.text
%include "io.mac"
		.STARTUP
		PutStr	prompt_msg	
		GetInt	EDX
	 
		call	fibonacci
		PutStr	output_msg1		; display Fibonacci number
		PutInt	EDX
		PutStr	output_msg2
		PutInt	EAX		  
done:
		.EXIT
;------------------------------------------------------------------------------------------
; Procedure Fibonacci receives an integer in DX and computes the largest Fibonacci number
; that is less than or equa to the input number.
; The fibonacci number is returned in AX.
;------------------------------------------------------------------------------------------
fibonacci:
		push	EBX
		; AX maintains the smaller of the last two Fibonacci numbers computed.
		; BX maintains the lagrer of the last two Fibonacci numbers computed.

		mov		EAX,1		; initialize AX and 
		mov		EBX,EAX		; BX to the first two fibonacci numbers
	fib_loop:
		add		EAX,EBX		; compute next Fibonacci Number
		xchg	EAX,EBX		; maintain the required order
		cmp		EBX,EDX		; compare with input number in DX
		jle		fib_loop	; if not greater, find next number
		; AX contains the required Fibonacci number
		pop		EBX
		ret
 