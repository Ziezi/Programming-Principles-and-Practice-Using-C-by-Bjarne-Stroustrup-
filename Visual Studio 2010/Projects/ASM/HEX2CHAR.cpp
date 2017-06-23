// ASM.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
// Inline assembly language
	__asm
	{
//	TITLE Hex equivalent of characters HEX2CHAR
//	COMMENT
//			Object: to print the hex equivalent of an ASCII character code (using the xlat instruction)
//			 Input: requests a character from keyboard
//			Output: prints the ASCII code of the input character in hex
	 
	section.data
	char_prompt DB 'Please input a character', 0
	out_msg1	DB 'The ASCII code of ''', 0 
	out_msg2	DB ''' in hex is: ', 0
	query_msg   DB 'Do you want to quit (Y/N): ', 0 
	// translation table: 4-bit binary to hex
	hex_table	DB '0123456789ABCDEF'

	section.text
	%include "io.mac"
			.STARTUP
    read_char:
		PutStr	char_prompt
		GetCh	EAL
		nwln
		PutStr	out_msg1
		GetStr	EAL
		PutStr	out_msg2
		mov		EAH,EAL
		mov		EBX,hex_table	// copy the starting address of 'hex_table' in BX
		shr		EAL,4
		xlatb							// replace AL with hex digit
		PutCh	EAL						// write the first hex digit
		mov		EAL,EAH					// restore AL
		and		EAL, 0FH					// mask the upper four bits
		xlatb							// write tre second hex digit
		 
		PutStr	query_msg				// ask whether to quit 'Y' / continue 'N'
		GetCh	EAL						// read response saved in AL
		 
		cmp		EAL,'Y'					 
		jne		read_char
	done:
		.EXIT
	}


	return 0;
}