; TITLE	Mix-mode Programming Parameter Passing (by-value; by-reference)  minmax_c.cpp
; COMMENT
;		Objective: To illustrate call-by-value and call-by-reference parameter passing 
;				   between C and assembly language modules.
;			Input: Requests three integer parameters.
;		   Output: Prints the minimum and maximum of the inputed integers.

PUBLIC	_min_max

; TITLE	Mix-mode Programming Parameter Passing (by-value; by-reference)  minmax_a.asm
; COMMENT
;		Objective: To illustrate call-by-value and call-by-reference parameter passing 
;				   between C and assembly language modules.
;			Input: Three integer parameters passsed by value or reference.
;	       Output: Returns the result to the calling C function.

PUBLIC	_min_max
section.text
_min_max:
		enter	0,0
		; AX = minimum, DX = maximum
		mov		AX,[BP+4]				; get value1 from the stack
		mov		DX,[BP+6]				; get value2 from the stack
		cmp		AX,DX					; value1 < value2
		jl		skip1
		xchg	AX,DX					; if value1 > value2 => exchange
	skip1:
		mov		CX,[BP+8]				; get value3 from the stack
		cmp		CX,AX					
		jl		new_min					; if,  value3 < min in AX
		mov		DX,CX
		jmp		store_result
	new_min:
		mov		AX,CX
	store_result:
		mov:	BX,[BP+10]				; BX := &minimum
		mov		[BX],AX
		mov		BX,[BP+12]				; BX := &maximum
		mov		BX,DX
		leave
		ret
		end
