// ASM.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
// Inline assembly language
	__asm
	{
//	TITLE Add individual digits of a number ADDIGITS
//	COMMENT
//		Objective: To find the sum of individual digits of a given number.
//				   Shows character to binary conversion of digits
//			Input: Requests a number from the keyboard 
//		   Output: Prints the sum of the individual digits
	 
	 
	section.data
	number_prompt	BYTE	'Please enter a number (<11 digits): ', 0
	out_msg			BYTE	'The sum of individual digits is: ', 0

	section.bss
	number			RESB 11 times (?)

	section.text
	//%include "io.mac" 
			 
			PutStr	number_prompt			// request an input number
			GetStr	number, 11				// save input number in 'number' (size=11bytes)
			 
			mov		ebx,number				// copy the base address (of the first digit) in BX
			sub		edx,edx					// initialize DX to 0, used for the sum accumulator
	repeat_add:
			mov		al,[ebx]				// copy the digit pointed by BX to AL
			cmp		al, 0
			je		done					// if AL is the NULL character sum is done
			and		 al,OFH					// mask the upper half of the byte
			add		 dl,al					// DL = DL + AL , DL initialized to 0
			inc		ebx						// increment to the next address
			jmp		repeat_add
	done:
			PutStr	out_msg
			PutInt	EDX						// display (write) sum
			 
			.EXIT
	}


	return 0;
}

