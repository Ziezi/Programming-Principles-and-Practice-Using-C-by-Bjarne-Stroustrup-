; TITLE	Sorting an array by insertion sort	INS_SORT.ASM
; COMMENT
;		Object: To sort integer array by using insertion sort.
;		 Input: Requests number to fill array.
;		Output: Display sorted array

 
section.data

input_prompt DB	"Please insert input array: "
				"(negative number terminates input)", 0
out_msg		 DB	"The sorted array is:", 0

section.bss
MAX_SIZE	 %define	100
array		 RESW	MAX_SIZE DUP (?)

section.text
%include "io.mac"
		.STARTUP
		PutStr	input_prompt
		mov		EBX,array			; BX = base address of the array, i.e. array[0]
		mov		ECX,[MAX_SIZE]				; CX = MAX_SIZE (=100bytes) ,loop counter max value (terminates after 100 inserted numbers)
array_loop:
		GetInt	EAX						; read an array number 
	 
		cmp		EAX,0					; checks if negative number,
		jl		exit_loop				; if negative => terminate input loop
		mov		[EBX],EAX					; otherwise copy into array
		add		EBX,2					; increment BX pointer by 2 (i.e. array-element-size == 2bytes)
		loop	array_loop				; iterates to: MAX_SIZE 
exit_loop:
		mov		EDX,EBX					; DX = actual array size
		sub		EDX,array			; DX = array size in bytes
		shr		EDX,1					; divide by 2 to get the actual size	
		push	EDX						; save size on the stack	(registers possibly used by called procedure)
		push	array					; save base address on the stack
		call	insetion_sort		
		PutStr	out_msg					; display sorted array
		 
		mov		ECX,EDX
		mov		EBX,array
display_loop:
		PutInt	[EBX]
		 
		add		EBX,2
		loop	display_loop
done:
		.EXIT
 

;--------------------------------------------------------------------------------------------
; This procedure receives a pointer to an array of integers 
; and the array size via the stack
; The array is sorted using insertion sort.
; All registers are preserved
;--------------------------------------------------------------------------------------------
SORT_ARRAY	%define	 [EBX]					
insertion_sort:
		pusha
		mov		EBP,ESP
		mov		EBX,[EBP+18]					; copy array pointer
		mov		ECX,[EBP+20]					; copy array size
		mov		ESI,2						; array left of SI is sorted (SI+2=i+1)
for_loop:
		; variables of the algorithm are mapped as follows 
		; EDX = temp, ESI = i, and EDI = j
		mov		EDX,SORT_ARRAY[SI]			; temp := array[i]
		mov		EDI,ESI						; j = i-1 
		sub		EDI,2
while_loop:
		cmp		EDX,SORT_ARRAY[EDI]			; temp < array[j]
		jge		exit_while_loop
		; array[j+1] := array[j]
		mov		SORT_ARRAY[EDI+2],EDX
		add		ESI,2						; i:=i+1
		dec		ECX
		cmp		ECX,1						; if CX = 1, we are done
		jne		for_loop
sort_done:
		popa
		ret		4
 

