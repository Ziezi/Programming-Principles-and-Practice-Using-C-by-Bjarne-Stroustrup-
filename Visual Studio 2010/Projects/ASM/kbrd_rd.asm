; TITLE	 Keyboard string read procedure	kbrd_rd.asm
; COMMENT
;		Objective: To show the implementation of GetStr macro-like procedures
;			Input: Keyboard input characters
;		   Output: -

;--------------------------------------------------------------------------------
; Get string (of maximum length 80) from keyboard.
; AX - pointer to a buffer to store the input string
; CX - buffer size = string length + NULL (string end indicator)
; If CX < 2 : CX := 2 is used to read at least one character.
; If CX > 81: CX := 81 is used to read the most 80 characters.
;--------------------------------------------------------------------------------

proc_GetStr	PROC
		push	DX			; save registers
		push	SI
		push	DI
		push	ES
		mov		DX,DS		; set up ES to point to DS
		mov		ES,DX		; for string instruction use
		mov		DI,AX		; DI = buffer pointer
		; check CX bounds
		cmp		CX,2
		jl		set_CX_2
		cmp		CX,81
		jle		read_str
		mov		CX,81
		jmp		SHORT read_str
	set_CX_2:
		mov		CX,2
	read_str:
		; use temporary buffer str_buffer to read a string in
		; using function 0AH of int 21H
		mov		DX,OFFSET str_buffer
		mov		SI,DX
		mov		[SI],CL		; first byte = # of chars. to read 
		DOScall	0AH
		inc		SI			; second byte = # of chars. read
		mov		CL,[SI]		; CX = # bytes to copy
		inc		SI			; SI = input string firsr char.
		cld
		rep		movsb
		mov		BYTE PTR [DI],0		; append NULL character (terminate string)
		pop		ES			; restore registers
		pop		DI
		pop		SI
		pop		DX
		ret
proc_GetStr	ENDP		