
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

align 16
string_to_int:
        xor     r9, r9
        xor     rax, rax
	xor	rcx, rcx
        mov     qword r8, [rdi]
        cmp     byte r8b, 0x2D                  ; is negative (-)?
        jz      .sav_neg
        cmp     byte r8b, 0x30                  ; check whether character is valid
        jb      .abort
        cmp     byte r8b, 0x39
        ja      .abort
        xor     byte r8b, 0x30
        add     byte al, r8b
.pre_loop:
        mov     r10, 1D
        mov     r11, 10D
        xor     rsi, rsi
        shr     r8, 8D
	inc	rcx
.loop:
        cmp     r8b, 0x30                       ; check whether character is valid
        jb      .app_neg
        cmp     r8b, 0x39
        ja      .app_neg
        mul     r11
        xor     byte r8b, 0x30
        mov     byte sil, r8b
        add     rax, rsi
	inc	rcx
        inc     r10
        cmp     r10, 8D
        jae     .fetch
        shr     r8, 8D
        jmp     .loop
align 16
.fetch:
        xor     r10, r10
        lea     rdi, [rdi + 8D]
        mov     qword r8, [rdi]
        jmp     .loop
align 16
.sav_neg:
        not     r9
        jmp     .pre_loop
align 16
.app_neg:
        test    r9, r9
        jns     .ret
        neg     rax
        js      .ret
        jz      .ret
        dec     rax
.ret:
	mov	rdx, rcx
        ret
align 16
.abort:
        mov     rax, -1D
	mov	rdx, rcx
        ret
