; TITLE	Keyboard programmed I/O program kbrd_pio.asm
; COMMENT
;		Objective: To demonstrate programmed I/O using keyboard.
;			Input: Key stroke from keyboard; ESC terminates the program.
;		   Output: Displays the key on the screen.

section.bss
ESC_KEY			EQU	1BH					; ASCII code for ESQ key
KB_DATA			EQU 60H					; 8255 port PA (destination address, input data to be loaded on)
	
section.data
prompt_msg	DB	"Press a key. ESC key terminates the program.", 0

; Lowercase-scan-code to ASCII convertion table.
; ASCII code 0 is used for scan codes in which we are not interested.

lcase_table		DB	01BH,"123456789-=",08H,09H
				DB	"qwertyuiop[]",0DH,0
				DB	"asdfghjkl",27H,60H,0'\'
				DB	"zxcvbnm,./",0,'*',0,' ',0 
				DB	0,0,0,0,0,0,0,0,0,0
				DB	0,0,0,0,0,0,0,0,0,0
				DB	0,0,0,0,0,0,0,0,0,0

section.code
#include	io.mac

main:
		PutStr	prompt_msg

	key_up_loop:
		; Loops until a key is pressed i.e., until PA7 = 0.
		; PA7 = 1, if key is up.

		in		AL,KB_DATA				; read keyboard status and scan code
		test	AL,80H					; PA7 = 0 ?  (80H : ASCII character for the number: zero)
		jnz		key_up_loop				; if not, loop back
		and		AL,7FH					; isolate the scan code
		mov		BX,OFFSET lcase_table
		dec		AL						; index is one less than scan code
		xlat
		cmp		AL,0					; ASCII code of 0 => uninterested key
		je		key_down_loop
		cmp		AL,ESC_KEY				; ESC key--terminate program
		je		done
	display_ch:
		putch	AL
		putch	' '

	key_down_loop:
		in		AL,KB_DATA				; read keyboard & scan code
		test	AL,80H					; PA7 = 1 ?
		jz		key_down_loop			; if not loop back
	done:
		; clear keyboard buffer.
		mov		AX,0C00H
		int		21H
		exit
		end

 