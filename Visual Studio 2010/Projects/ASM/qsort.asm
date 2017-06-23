; TITLE	 Sorting integers using quicksort	qsort.asm
; COMMENT	
;		Objective: Sorts an array of integers using quick sort. Uses recursion.
;		    Input: Requests integerers from the user.
;		   Output: Outputs the sorted array.

section.data
prompt_msg		DB	"Please enter integers.", 0DH,0AH
				DB	"Entering zero terminates the input",0
output_msg		DB	"The sorted array is: ",0

section.bss
array1			DW	200	DUP(?)

section.text
%include "io.mac"

main:
		.STARTUP
		PutStr	prompt_msg
		nwln
		mov		EBX,OFFSET array1
		xor		EDI,EDI					; EDI (count of the input numbers) initialized to 0
read_more:
		GetInt	EAX
		nwln
		mov		[EBX+EDI*2],AX			; input element stored in the array
		cmp		EAX,0					; test if imput element 0
		je		exit_read
		inc		EDI
		jmp		read_more

exit_read:
		; prepare elements for prodecure call
		mov		EBX,OFFSET array1
		xor		ESI,ESI					; ESI = lo index
		dec		EDI						; EDI = hi index
		call	qsort

		PutStr	output_msg				; outputs sorted array
write_more:
		; since qsort preserves all registers
		; we will have valid EBX and ESI values.
		mov		EAX,[EBX+ESI*2]
		cmp		EAX,0
		je		done 
		PutInt	EAX
		nwln
		inc		ESI
		jmp		write_more

done:
		ret
		.EXIT

;---------------------------------------------------------------------
; Procedure qsort receives a pointer to the array in BX.
; LO and HI are received in ESI and EDI, respectively.
; It preserves all the registers.
;---------------------------------------------------------------------

qsort:
		pusha
		cmp		EDI,ESI
		jle		qsort_done					; end recursion if hi <= lo

		; save hi and lo for later use
		mov		ECX,ESI
		mov		EDX,EDI

		mov		AX,[EBX+EDI*2]				; AX = xsep

lo_loop:
		cmp		[EBX+ESI*2],AX
		jge		lo_loop_done				; LO while loop
		inc		ESI
		jmp		lo_loop
lo_loop_done:
		
		dec		EDI							; hi = hi - 1
hi_loop:
		cmp		EDI,ESI
		jle		sep_done 
		cmp		[EBX+EDI*2],AX				; HI while loop
		jle		hi_loop_done
		dec		EDI
		jmp		hi_loop
hi_loop_done:
		
		xchg	EAX,[EBX+ESI*2]
		xchg	EAX,[EBX+EDI*2]				; x[i] <=> x[j]
		xchg	EAX,[EBX+ESI*2]
		jmp		lo_loop
		
set_done:
		
		xchg	EAX,[EBX+ESI*2]
		xchg	EAX,[EBX+EDX*2]				; x[i] <=> x[hi]
		xchg	EAX,[EBX+ESI*2]

		dec		ESI
		mov		EDI,ESI						; hi = i - 1
		; We will modify the value of ESI in the next statement.
		; Since the original ESI value is in EDI, we will use.
		; DSI value to get i+1 value for the second qsort call.
		mov		ESI,ECX
		call	qsort

		; EDI has the i value 
		inc		EDI
		inc		EDI
		mov		ESI,EDI					; lo = lo + 1
		mov		EDI,EDX
		call	qsort

qsort_done:
		popa
		ret
