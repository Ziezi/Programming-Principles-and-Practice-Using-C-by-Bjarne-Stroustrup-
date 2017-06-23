;TITLE	Binary search of a sorted integer array bin_srch.asm
;COMMENT
;		Objective: To implement binary seach of a sorted integer array.
;			Input: Requests numbers to fill array and a number to be searched for from user.
;		   Output: Dislpays the position of the number in the array if found; otherwise, not found message

 
section.data
input_propmt	DB	"Please enter input array	(in sorted order): "
				DB	"(negative numbers terminates input)", 0 
query_number	DB	"Enter the number to be searched:", 0
out_msg			DB	"The number is at position", 0
not_found_msg	DB	"Number not in the array!", 0
guery_msg		DB	"Do you want to quit?", 0

section.bss
MAX_SIZE		%define	100
array			DW	MAX_SIZE DUP (?)

section.text
 
%include	"io.mac"
			.STARTUP
			PutStr	input_prompt
		 
			sub		ESI,ESI				; initialize ESI to 0
			mov		ECX, MAX_SIZE		
array_loop:
			GetInt	EAX					; read an array nunber
		 
			cmp		EAX,0				; check if number is negative
			jl		exit_loop			; if negative => terminate input
			mov		array[ESI*2],EAX	; otherwise, copy into array
			inc		ESI					; increment array index
			loop	array_loop			; itterates to MAX_SIZE
read_loop:
			PutStr	query_number		; requests number to be searched for
			GetInt	EAX					; read number
			nwln
			push	EAX
			push	ESI
			push	array
			call	binary_search
			; binary_search returns result (position of the number in the array) in AX
			; if not found returns 0
			cmp			EAX,0			; number found?
			je			not_found		; if not found: display number not found
			PutStr		out_msg			; else, display number position
			PutInt		EAX
			jmp			user_query
not_found:
			PutStr		not_found_msg
user_query:
			 
			PutStr		query_msg		; asks user whether to terminate
			GetCh		EAL				; read response
			nwln
			cmp			EAL,'Y'			; if resopnse is not 'Y'
			jne			read_input		; repeat the loop
done:									; otherwise, terminate the program
			.EXIT
 

;----------------------------------------------------------------------------------------------------------------------------
; This procedure receives a pointer to an array of integers, the array size, and the number to be searched via the stack.
; It returns in AX the position of the number in the array if found, otherwise ,returns 0.
; All registers, except AX, are preserved
;-----------------------------------------------------------------------------------------------------------------------------

binary_search		PROC
			enter	0,0
			push	EBX
			push	ESI
			push	CX
			push	DX
			xor		EBX,EBX				; EBX = 0
			mov		BX,[BP+4]			; copy array pointer
			mov		CX,[BP+6]			; copy array size
			mov		DX,[BP+8]			; copy number to be searched
			xor		AX,AX				; lower = 0
			dec		CX					; upper = size - 1
while_loop:
			cmp		AX,CX				; lower > upper ?
			ja		end_while
			sub		ESI,ESI
			mov		SI,AX				; middle = (lower + upper)/2
			add		SI,CX
			shr		SI,1
			cmp		DX,[EBX+ESI*2]		; number = array[middle]? (middle = base + index*scale)
			je		seach_done
			jg		upper_half
lower_half:
			dec		SI					; middle = middle - 1
			mov		CX,SI				; upper = middle - 1
			jmp		while_loop
upper_half:
			inc		SI					; middle = middle + 1
			mov		AX,SI				; lower	= middle + 1
			jmp		while_loop
end_while:
			sub		AX,AX				; number not found	(clear AX)
			jmp		skip1
seach_done:
			inc		SI					; position = index + 1
			mov		AX,SI				; return position 
	 skip1:
			pop		DX
			pop		CX
			pop		ESI
			pop		EBX
			leave
			ret		6
	binary_search	ENDP
			END		main				