; <check_primedigit>
; A small program that checks if the supplied number is a primedigit,
; returning a boolean 0 for false and 1 for true
; The focus is on performance

; reset to default values
mvi a, 0
mvi b, 0
mvi c, 0
mvi d, 0
mvi e, 0

; Input here the number to check (max 255)
mvi a, 234

; Here starts the actual code
; Check if digit is smaller than 18
mvi e, 18
cmp e
jc
