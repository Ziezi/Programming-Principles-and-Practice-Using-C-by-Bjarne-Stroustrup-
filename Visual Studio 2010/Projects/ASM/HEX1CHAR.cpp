// ASM.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
// Inline assembly language
	__asm
	{
//	TITLE Hex equivalent to characters HEX1CHAR
//	COMMENT
//			Object: To print the hex equivalent of ASCII character code.
//			 Input: Reqeusts a character from keyboard.
//			Output: Prints the ASCII code of the input character in hex.
	//.MODEL SMALL
	//.STACK 100H
	section.data
	char_prompt	DB 'Please input a character', 0
	out_msg1	DB 'The ASCII code of''', 0
	out_msg2	DB 'in HEX is: ', 0
	query_msg	DB 'Do you want to quit (Y/N): ', 0

	section.text
	%include "io.mac"
			.STARTUP
	read_char:
			PutStr	char_prompt  // output(display) the message content of char_prompt
			GetCh	EAL		    // read input char and store in AL
			nwln
			PutStr	out_msg1		// output the message content of out_msg1
			PutCh	EAL			// output the content of AL (the inputted character)
			PutStr	msg_out2		// output the message content of out_msg2
			mov		EAH,EAL			// AH used as temporary stoage for the content of AL  
			shr		EAL,4			// bitwise shift-right of the contents of AL
			mov		ECX,2			// load CX (the 16-bit counter register) =2 (number of loops)
	print_digit:
			cmp		EAL,9			// determine convertion condition (0-9) or (A-F)
			jg		A_to_F			// jump to label: A_to_F if AL > 9
			add		EAL,'0'			// if AL < 9 , perform: + '0' translation
			jmp s	kip			// unconditional jump to label: skip
	A_to_F:
			add		EAL,'A'-10		// conditional jump: perform: +'A' - 10 translation
	skip:
			PutCh	EAL			// output (write) the first hex digit
		    mov		EAL,EAH			// retreive the original (unmodified) value ot the input character
			and		EAL,0FH			// mask off the upper half byte
			loop	print_digit
			 
			PutStr	query_msg	// terminate or enter additional character from keyboard
			GetCh	EAL			// get keyboard character 'Y' or 'N'
			 
			cmp		EAL,'Y'			// if (AL=Y) => AL - Y =  0 => ZF = 1
			jne		read_char		// if AL = N ,take the jump and read new character
	 done:
			.EXIT
	}
	return 0;
}