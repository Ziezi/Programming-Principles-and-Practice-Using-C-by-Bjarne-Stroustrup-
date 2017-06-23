;TITLE	Sum of a column (the third column) in a 2 - Dimensional array	test_array.asm
;COMMENT
;		Objective: To demonsrtate array index manipulation
;				   in a two-dimensional array of integers.
;			Input: None.
;		   Output: Displays the sum.

section.data
NO_ROW_BYTES	EQU NO_COLUMNS*2		; NumberOfBytesPerRow = NumberOfElementsInARow(num of columns)*BytesPerElement(2bytes)
class_marks		DW	90,89,99
				DW	98,78,67
				DW	78,87,78
				DW	98,56,87
				DW	78,76,89
sum_msg			DB	"The sum of the last test marks is: ", 0

section.bss
NO_ROWS			EQU	5
NO_COLUMNS		EQU	3

section.text
%include "io.mac"
main:
		.STARTUP
		mov		CX,NO_ROWS					; loop iteration count (sun over number of rows)
		sub		EAX,EAX						; sum = 0
		; ESI = index of class_marks[0,2]
		sub		EBX,EBX						; EBX(pointer to the first array element)
		mov		ESI,NO_COLUMNS-1			; ESI(ColumnIndex): end translated to NumberOfColumns-1 (it starts from 0)
sum_loop:
		add		EAX,class_marks[EBX+ESI*2]	; EBX(RowIndex(Up/Down)): + ESI(ColumnIndex(Left/Right))*(SizeOfElemntInRow)
		add		EBX,NO_ROW_BYTES			; increment EBX(RowIndex) by adding the bytes equal in size of all elements in a row
		loop	sum_loop
		
		PutStr	sum_msg
		PutInt	EAX
		nwln
done:
		.EXIT
		ret
