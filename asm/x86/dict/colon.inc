; Macro that creates a linked list (dictionary)
; %1 = dictionary keys (quoted)
; %2 = Assembly label name. (Keys contain special characters, which are not allowed in label names)
%macro colon 2
%2:
	db %1, 0
	%ifndef LLLAST
		dq 0
	%else
		dq LLLAST
	%endif
	%define LLLAST %2
%endmacro
