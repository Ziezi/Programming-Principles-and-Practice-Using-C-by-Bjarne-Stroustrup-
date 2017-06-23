; TITLE	Assembly program to find sum	sumprog.asm
; COMMENT
;		Objective: To add two integers.
;			Input: Two integers
;		   Output: Sum of input numbers.

section.data
prompt_msg1		DB	"Enter first number.", 0
prompt_msg2		DB	"Enter second number.", 0
sum_msg			DB	"Sum is: ", 0
error_msg		DB	"Overflow has occured!", 0

secion.bss
number1			DD	?								; buffer for the first number, size 32-bit
number2			DD	?				
sum				DD	?			

section.code
#include "io.mac"
 
main:
		.STARTUP
		; prompt user first number
		PutStr	prompt_msg1
		GetLint	number1
		 

		; prompt user second number
		PutStr	prompt_msg2
		GetLint number2 
		 

		; finds sum of the two numbers
		mov		EAX, number1
		add		EAX, number2
		mov		sum, EAX

		; checks for overflow
		jno		no_overflow
		PutStr	error_msg
		nwln
		jmp		done

		; display sum
no_overflow:
		PutSrt	sum_msg
		PutLint	sum
		 
done:
		.EXIT
		ret