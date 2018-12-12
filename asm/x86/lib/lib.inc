%ifndef LIB_INC
	%define LIB_INC

; AMD64 functions that are similar to a few of the C stdlib functions
;
;	functions defined
;	- exit
;	- string_length
;	- print_char
;	- print_string
;	- print_newline
;	- print_uint
;	- print_int
;	- read_char
;	- read_string
;	- read_word
;	- string_to_uint
;	- string_to_int
;	- string_equals
;	- string_copy
;	- calliso


; -[exit]-
; Terminates the program
; takes:
;       rdi - exit code of program
; edtis:
;       rax, rcx, r11
; returns:
;       nothing

global _exit


; -[string_length]-
; Counts the length of a string till \0 sign
; takes:
;       rdi - address of string
; modifies:
;       rax, r8, r9, r10, r11
; returns:
;       rax - size of the string counted without \0 sign

global	string_length


; -[print_char]-
; Print a single character to stdout
; takes:
;       rdi - character to print
; modifies:
;       rax, rdx, rsi, rdi, rcx, r11
; returns:
;       nothing

global	print_char


; -[print_string]-
; Print a sequence of character to stdout
; takes:
;       rdi - address of string
; modifies:
;       rax, rdx, rsi, rdi, rcx, r11
; returns:
;       nothing

global	print_string


; -[print_newline]-
; Print the newline (0x0A / \n ) character to stdout
; takes:
;       nothing
; modifies:
;       rax, rdx, rdi, rsi, rcx, r11
; returns:
;       nothing

global	print_newline


; -[print_uint]-
; Print unsigned integer in decimal base to stdout
; takes:
;       rdi - unsigned integer to be printed
; modifies:
;       rax, rdx, rcx, rsi, rdi, r9, r10, r11
; returns:
;       nothing

global	print_uint


; -[print_int]-
; Print signed integer in decimal base to stdout
; takes:
;       rdi - signed integer to be printed
; modifies:
;       rax, rdx, rcx, rsi, rdi, r9, r11
; returns:
;       nothing

global	print_int


; -[read_char]-
; Read one character from stdin
; takes:
;       nothing
; modifies:
;       rax, rdx, rsi, rdi, rcx, r11
; returns:
;       rax - character read from stdin

global	read_char


; -[read_string]-
; Read a string of fixed maximum size from stdin, removes \n from the end
; takes:
;       rdi - buffer address to save the string to plus space for \0 sign
;       rsi - size of the buffer
; modifies:
;       rax, rdx, rdi, rsi, rcx, r11
; returns:
;       rax - returns buffer starting address

global	read_string


; -[read_word]-
; Read a word of fixed size, stops reading at space, tab, newline character
; or term \0 sign, if the specified size is exceeded return 0
; takes:
;       rdi - buffer address to save the string to, requires one more space than
;             the size of the string for \0 sign
;       rsi - size of buffer
; modifies:
;       rax, rdx, rdi, rsi, rcx, r8, r9, r10, r11
; returns:
;       rax - buffer starting address, or 0 if failed

global	read_word


; -[string_to_uint]-
; parse a string containing a unsigned number to an unsigned integer
; takes:
;       rdi - string address to read from, string must be terminated with \0
; modifies:
;       rax, rdx, rcx, rdi, r9, r10, r11
; returns:
;       rax - unsigned integer value, -1 on failure
;	rdx - number of characters processed

global	string_to_uint


; -[string_to_int]-
; parse a string containing a signed number to an signed integer
; takes:
;       rdi - string address to read from, string must be terminated with \0
; modifies:
;       rax, rcx, rdx, rsi, rdi, r8, r9, r10, r11
; returns:
;       rax - signed integer value, -1 on failure
;	rdx - number of characters processed

global	string_to_int


; -[string_equals]-
; Compares two strings, if equal return 1, if not 0
; takes:
;	rdi - address to first string
;	rsi - address to second string
; modifies:
;	rax, rdx, rdi, rsi, r8, r9
; returns:
;	rax - 1 if strings are equal, 0 if not

global	string_equals


; -[string_copy]-
; Copies string to destination
; takes:
;	rdi - address of string
;	rsi - address of buffer (destination)
;	rdx - length of buffer
; modifies:
; 	rax, rcx, rsi, rdi, r9, r10, r8
; returns:
;	rax - buffers address if string can by copied, 0 otherwise

global	string_copy


; -[calliso]-
; Call isolator, makes a call to the address pushed previously onto the stack,
; used mainly for debugging functions
; takes:
;       Address to function, must be pushed to stack before calling
;       this function
; modifies:
;       rax - return value of called function, if modified by function
;       It resets other modification made by the function 
; returns:
;       rax - return value of called function, if modified by function

global calliso

%endif ; LIB_INC
