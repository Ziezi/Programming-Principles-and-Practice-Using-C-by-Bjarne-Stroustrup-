; TITLE  Mix-mode programming function call  testex_a.asm
; COMMENT
;		 Objective: To show C++ procedure call from an assemlby module.
;			Input: - (immediate parameter passing).
;		   Output: It prints the result from the assembly procedure manipulation over the parameters passed from the C++ module.

#include "StdAfx.h"

PUBLIC __test
__test:
		enter	0,0
		mov		AX,[BP+4]				; get argument1 = x
		add		AX,[BP+6]				; get argument2 = y
		sub		AX,[BP+8]				; get argument3 from sum
		leave
		ret								; stack to be cleared by C function
		end		