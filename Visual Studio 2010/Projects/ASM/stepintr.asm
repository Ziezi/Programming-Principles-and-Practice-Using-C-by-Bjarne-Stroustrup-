; TITLE	Single-step program stepint.asm
; COMMENT
;		Objective: To demonstrate how Interrupt Service Routine (ISR) can be defined and installed.
;			Input: None.
;		   Output: Displays AX and BX values for the single-step code.

segment.bss
old_offset		DW	?			; for old ISR offset
old_seg			DW	?			; and segment values 

segment.data
start_msg		DB	"Starts single-stepping process.",0
AXequ			DB	"AX = ",0
BXequ			DB	"BX = ",0

segment.code
# include "io.mac"

main:
		PutStr  start_msg

		; get current interrupt vector for int 1H
		mov		AX,3501H		; AH = 36H and AL = 01H	
		int		21H				; returns the offset in BX
		mov		old_offset,BX	; and the segment in ES
		mov		old_seg,ES

		; set up interrupt vector to out ISR
		push	DS				; DS is used by function 25H
		mov		DS,AX			; copy current segment to DS
		mov		DS,AX
		mov		DS,OFFSET sstep_ISR	; ISR offset in DX
		mov		AX,2501H		; AH = 25H and AL = 1H
		int		21H
		pop		DS				; restore DS

		; set trap flag to start single_stepping
		pushf
		pop		AX				; copy flags into AX
		or		AX,100H			; set up flag bit (TF = 1)
		push	AX				; copy modified flag bits
		popf					; back to flags register

		; from now on int 1 is generated after executing 
		; each instruction. Some test instructions follow.
		mov		AX,100
		mov		BX,20
		add		AX,BX

		; clear trap flag to end single-stepping
		pushf
		pop		AX				; copy flags into AX
		and		AX,0FEFFH		; clear trap bit (TF = 0)
		push	AX				; copy modified flag bits
		popf					; back to flag register 

		; restore the original ISR 
		mov		DX,old_offset
		push	DS
		mov		AX,old_seg
		mov		DS,AX
		mov		AX,2501H
		int		21H
		pop		DS
		exit
		end
;-------------------------------------------------------------------------------------
; Single-step interrupt service routine replaces int 01H
;-------------------------------------------------------------------------------------
sstep_ISR:
		sti						; enable interrupt
		PutStr	AXequ			; displays AX contents
		PutInt	AX
		PutStr	BXequ			; displays BX contents 
		PutStr	BX

		iret 
		end
		end