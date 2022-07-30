
#ifndef STRING_EQUALS_H
#define STRING_EQUALS_H


/*
  -[string_equals]-
  Compares two strings, if equal return 1, if not 0
  takes:
 	rdi - address to first string
 	rsi - address to second string
  returns:
 	rax - 1 if strings are equal, 0 if not
*/

extern long string_equals(char *, char *);

#endif /* STRING_EQUALS include guard */
