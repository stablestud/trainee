mvi a, 0
mvi b, 0
mvi c, 0
mvi d, 0
mvi e, 0

mvi a, 27
mvi e, 20

cmp e
hlt

; Bei ist kleiner als:
; S 1
; Z 0
; AC 0
; P 1 - bei groesseren Zahlen nicht mehr??
; C 1 (on carry)

; Bei gleichheit:
; S 0
; Z 1 (on zero)
; AC 0
; P 1
; C 0

; Bei groesser als:
; S 0 
; Z 0
; AC 0
; P 0 - bei grossen Abstand anderer Wert
; C 0 (on zero carry)
