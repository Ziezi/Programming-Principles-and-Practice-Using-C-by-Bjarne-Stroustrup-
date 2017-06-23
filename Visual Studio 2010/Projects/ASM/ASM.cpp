// ASM.cpp : Defines the entry point for the console application.
//

	#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
// Inline assembly language
	__asm
	{
		nop
		nop
		nop
		mov eax, 0xfffffff
		mov al, 2
		mov ah, 2
		mov ax, 2
		mov eax, 2
	}


	return 0;
}

