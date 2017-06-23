// ASM.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
// Inline assembly language
// TITLE Binary equivalent of characters BINCHAR.cpp
// COMMENT
//			Objective: to print the binary equivalent of ASCII character code.
//				Input: requests a character from keyboard.
//			   Output: prints the ASCII code of the input character in binary.
	__asm
	{
	//.MODEL SMALL
	//.STACK 100H
	section.data
	char_prompt   'Please input character: ', 0
	out_msg1	  'The ASCII code of''', 0 
	out_msg2	  ''' in binary is ', 0
	query_msg	  'Do you want to quit (Y/N): ', 0

	section.text
	%include "io.mac" 
			.STARTUP
	read_char:
			PutStr	char_prompt	// request a char. input
			GerCh	EAL			// read input character
			nwln 
			PutStr	out_msg1
			PutCh	EAL
			PutStr	out_msg2
			mov		EAH,80H		// mask byte = 80H (1000 0000B)
			mov		ECX,8		// loop count to print 8 bits 
	print_bit:
			test	EAL,EAH		// test does not modify AL 
			jz		print_0		// if tested bit is 0, print it
			PutCh	'1'			// otherwise, print 1
			jmp		skip1
	print_0:
			PutCh	'0'			// print 0
	skip1: 
			shr		EAH,1		// right-shift the mask bit to test next bit of the ASCII code
			loop	print_bit
			nwln 
			PutStr  query_msg	// query user whether to terminate 
			GetCh	EAL			// read response 
			nwln 
			cmp		EAL,'Y'		// if response is not 'Y'
			jne		read_char	// read another character
	done:
			.EXIT
	}


	return 0;
}