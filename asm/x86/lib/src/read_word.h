
#ifndef READ_WORD_H
#define READ_WORD_H


/*
  -[read_word]-
  Read a word of fixed size, stops reading at space, tab, newline character
  or term \0 sign, if the specified size is exceeded return 0
  takes:
        rdi - buffer address to save the string to, requires one more space than
              the size of the string for \0 sign
        rsi - size of buffer
  modifies:
        rax, rdx, rdi, rsi, rcx, r8, r9, r10, r11
  returns:
        rax - buffer starting address, or 0 if failed
*/

extern char *read_word(char const*, long);

#endif /* READ_WORD_H include guard */
