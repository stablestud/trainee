
section .text

; Iterate thru linked list (dictionary), look for key, if not found return 0, otherwise return key's value
; %1 = pointer to null terminated key string to look for
; %2 = pointer to last word in dictionary, so we can iterate thru the "dictionary"
global find_word

find_word:
	
