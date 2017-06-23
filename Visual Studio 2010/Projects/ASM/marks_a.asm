; TITLE	 C program calling assembly procedure and vise versa	marks_a.asm
; COMMENT	
;		Objective: To illustrate mix-mode program calling.
;			Input: Receives an array of integers and its size, passed by C program.
;		   Output: Returns a rounded average of the array elements to the C program.

EXTRN	_find_avg

section.text
PUBLIC _stats

_stats:
		enter	0,0
		push	SI
		push	DI 

		; AX - minimum, DX - maximum, Marks total = SI
		mov		BX,[BP+4]				; BX = marks array address
		mov		AX,[BX]					; min := first element 
		mov		DX,AX					; max := first element
		xor		SI,SI					; total := 0
		mov		CX,[BP+6]				; CX := class size
	repeat1:
		mov		DI,[BX]					; DI := current mark

		; compare and update minimum
		cmp		DI,AX					; if current element > current minimum element (AX = first el.)
		ja		skip1					; AX = remains current minimum
		mov		AX,DI					; otherwise current element = minimum
	skip1:
		; compare and update maximum
		cmp		DI,DX
		jb		skip2
		mov		DX,DI
	skip2:
		add		SI,DI					; update marks total
		add		BX,2					; point to the next element of the array
		loop	repeat1
		mov		BX,[BP+8]				; return minimum ; BX - loaded with the stack offset(address) contianing the min => BX is a pointer to the stack	
		mov		[BX],AX					; the content of BX (pointing to the stack location allocated for the minimum) loaded with the min 
		mov		BX,[BP+10]				; return maximum
		mov		BX,DX

		; now call find_avg C function to compute average 
		push	WORD PTR[BP+6]			; push class size
		push	SI						; push total marks  ; both required for the calculation of the average value
		call	_find_avg				; returns average in AX
		add		SP,4					; clears the stack
		mov		BX,[BP+12]				; return average2; BX pointer to the stack BP+12 location
		mov		[BX],AX					; the contents of the pointed location loaded with the result of the C function
		pop		DI
		pop		SI
		leave
		ret
		end