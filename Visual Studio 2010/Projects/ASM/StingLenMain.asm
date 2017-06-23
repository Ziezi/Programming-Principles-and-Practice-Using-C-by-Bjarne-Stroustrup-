; TITLE	Multimodule program for string length	StringLenMain.asm
; COMMENT
;		Objective: To show multiple module programming.
;			Input: Requests an input string from the keyboard.
;		   Output: Outputs the lenght of the string.


section.data
prompt_msg	DB	"Please input a string: ", 0
length_msg	DB	"String length is: ", 0

section.bss
BUF_SIZE	%define	41	; string buffer lenghth
string1		DB	BUF_SIZE	DUP(?)

section.text
%include "io.mac"
EXTRN	StringLenProc:PROC			; indicates that the label: StringLen is of type: procedure 
main:								; and it is defined in other module (will be invoked later on)
		.STARTUP
		PutStr	prompt_msg
		GetStr	string1,BUF_SIZE
		nwln
		mov		EBX,OFFSET string1	; BX:=string pointer
		call	StringLen		; returns string length in AX
		PutStr	length_msg			; display string length
		PutInt	EAX
		nwln
done:
		.EXIT
		ret