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

; a / e = b
set:	mvi a, 200
	mvi e, 10

; a saves the dividend, also the rest
; e is the divisor
; d is 0, to as comparison
; b saves the count

; loop:
; if a is smaller than e, jump to rest
; subtract a with e
; increment b by one
; if a == 0, jump to end, b holds the result of division
; else redo loop, a holds the decremented value
loop: 	cmp e	
	jc rest
	sub e 	
	inr b
	cmp d
	jz done
	jmp loop

rest:	out 1
	jmp end

done:	mov a, b
	out 0

end:	hlt
