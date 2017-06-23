; TITLE	Sum a long integer array	array_sum.asm
; COMMENT
;		Objective: To find sum of all elements of an array
;			Input: None
;		   Output: Displays the sum

 
 
section.data
test_marks		DD		90,50,65,79,84,78,85,56,65,75
NO_STUDENTS		%define	($-test_marks)/4					; numbers of students = length($-array_name)/size of element(4 bytes (DD))
sum_msg			DB		"The sum of test marks is: ", 0

section.text
%include "io.mac"
		.STARTUP
		mov		CX,NO_STUDENTS							; CX (loop iteration count) = number of array elements
		sub		EAX,EAX									; initialize EAX(sum) = 0
		sub		ESI,ESI									; initialize ESI(array index) = 0
add_loop:
		mov		EBX,test_marks[ESI*4]					; EBX(base pointer) = test_marks[0] element
		PutLInt EBX										; LInt : long integer (DD-32bit)
		nwln
		add		EAX,test_marks[ESI*4]					; sum = sum + test_marks[0]
		inc		ESI										; increment the ESI(index) to the next element in the array
		loop	add_loop

		PutStr	sum_msg
		PutLInt	EAX
		nwln
		.EXIT
 
