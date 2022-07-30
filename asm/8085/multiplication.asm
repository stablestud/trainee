
; @author stablestud
; @date 25.04.2018

; <multiplication>

; reset all
reset:	mvi a, 0
	mvi b, 0
	mvi c, 0
	mvi d, 0
	mvi e, 0
	mvi h, 0
	mvi l, 0
	jmp start

; d * e = c
set: 	mvi d, 3
	mvi e, 3

loop:	mov a, c
	add d
	mov c, a
	mov a, e
	inr b
	cmp b

	jz end	 ; when equal end program
	jmp loop ; if not, loop again

end: 	hlt

