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
	mvi e, 77

loop: 	cmp e	
	jc rest
	sub e 	
	inr b
	cmp d
	jz end
	jmp loop

rest:	mov c, a

end:	hlt
