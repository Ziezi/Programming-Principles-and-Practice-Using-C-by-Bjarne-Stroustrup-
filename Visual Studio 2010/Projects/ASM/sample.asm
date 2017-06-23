;TITLE	Sample of an assembly language program	 sample.asm			; prints text after TTITLE directive
;COMMENT																; in .lst file (after assembling)
;		Objective: To demonstrate the use of I/O routines			; everything within COMMENT directive,
;				   and show the structure of an assembly program. 
;			Input: As prompted.										; ignored by the assembler, 
;		   Output: As per unput.									; used for brief description
;.MODEL SMALL														; specifies the space allocated for the code and data (< 64K)
;.STACK 100H														; specifies the stack size (100H in hex = 256 Bytes)
section.data														; indicates the start of the data segment (pointer to the data segment)
name_msg		DB	"Please enter your name", 0						; syntax:[label] [type(size) identifier] [string of characters], initialized to 0
query_msg		DB	"How many times to repeat welcome message", 0
confirm_msg1	DB	"Repeat welcome message", 0
confirm_msg2	DB	"times? (y/n)", 0
welcome_msg		DB	"Welcome to Assembly Language Programming", 0

section.bss
user_name		DB	16 DUP (?)										; definition: buffer with size 16 bytes (no initialization)
response		DB	?												; definition: [label]= response size DB (8-bit)

section.text														; end of data segment, start of code segment
%include "oi.mac"													; INCLUDE directive: includes external source file contents
																	; io.mac: input/output  predefined macros facilitating I/O data
main:																; indicates an entry point to the assembler (PROC directive defines a procedure start)
		.STARTUP													; directive setting data and stack segments (corresponding to mov AX,@DATA; mov DS,AX)
		PutStr	name_str											; displays contents of the label: name_str defined in data segment
		nwln
		GetStr	user_name,16										; reads string into buffer with label: user_name, max size 16
		nwln
ask_count:															; loop label: start of a loop cycle
		PutStr	query_msg											; displays the contents of the label: query_msg
		GetInt	ECX													; reads an integer vsalue into CX register (later used as a counter in a loop)
		nwln
		PutStr	confirm_msg1										; displays the contents of the label: confirm_msg1
		PutInt	ECX													; display value to be confirmed
		PutStr	confirm_msg2	
		GetCh	response											; read into predefined buffer named: response (size 1byte)
		nwln
		cmp		response,"Y"										; compare the contents of the buffer: response with the character "Y"
		jne		ask_count											; if the buffer: response different from "Y", jump to label: ask_count									
dislpay_msg:
		PutStr	welcome_msg											; display welcome message
		PutStr  user_name											; display the user name
		nwln 
		loop	display_msg											; repeat, "count" times
		.EXIT	
		ret															; returns control from assembler program to operating system (mov AX,4C00; int 21C)
																	; indicates end of procedure named "main"
																	; signals the assembler that the end of the source file has been reached 



