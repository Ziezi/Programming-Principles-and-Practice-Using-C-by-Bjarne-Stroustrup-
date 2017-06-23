// ASM.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
// Inline assembly language
	__asm
	{
//	TITLE uppercase convertion of charactes TOUPPER
//	COMMENT
//			Objective: To convert lowercase to corresponding uppercase letters.
//				Input: Requests a character string from the keyboard
//				Output: Prints the input character string in uppercase
	section.data
	name_prompt DB 'Please enter your name: ', 0
	out_msg		DB 'Your name in capitas os: ', 0

	section.bss
	in_name		DB 31 DUP (?)

	section.code
	#include "oi.mac"
	main:
			.STARTUP
			PutStr	name_prompt			// requests character string 
			GetStr	in_name,31			// saves the input character string
			nwln
			PutStr	out_msg
			mov		EBX,in_name	// starting (base) addres of the first character of the string is saved in BX
	process_char:
			mov		EAL, [EBX]			// move the string in AL
			cmp		EAL,0				// if it is the NULL character, 
			je		done				// convertion done, jump to end 
			cmp		EAL,'a'				// if (char <'a') (lowercase characters have larger hex code words than upper case chars)
			jl		not_lower_case		  
			cmp		EAL,'z'				// the lowercase letters are within the interval char: a,....,z or hex: 61,....,7A 
			jg		not_lower_case
	lower_case:
			add		EAL,'A'- 'a'			// convert to uppercase (hex of lowecase > hex of uppercase)
	not_lower_case:	
			PutCh	EAL					// the character is already an uppercase 
			inc		EBX					// increment pointer to the next char in the string
			jmp		process_char		// go back to process next char
			nwln
	done:
			.EXIT
			ret











	}


	return 0;
}

