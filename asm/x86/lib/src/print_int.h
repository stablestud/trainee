
#ifndef PRINT_INT_H
#define PRINT_INT_H

/*
  -[print_int]-
  Print signed integer in decimal base to stdout
  takes:
        rdi - signed integer to be printed
  modifies:
        rax, rdx, rcx, rsi, rdi, r9, r11
  returns:
        nothing
*/

extern void print_int(int);

#endif /* PRINT_INT_H include guard */
