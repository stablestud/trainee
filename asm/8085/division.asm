; @author stablestud
; @data 25.04.2018

; <division/modulo>
; b = quotient
; c = rest

; reset to default values
reset:	mvi a, 0
	mvi b, 0
	mvi c, 0
	mvi d, 0
	mvi e, 0

; d / e = b
set:	mvi a, 200
	mvi e, 33

loop: 	mov a, d
; check if divisor
; is greater then dividend
	cmp e
	jc rest
; - - - - - - - - - - - -
	sub e 	
	mov d, a
; Speed can be further 
; improved by keeping d in
; the accu and instead,
; compare it to a register
; with value of 0
; (would save 9 bytes)
 	mvi a, 0 
	inr b
	cmp d
	jz end
	jmp loop

rest:	mov c, a

end:	hlt
