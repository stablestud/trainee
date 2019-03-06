
#ifndef STRING_COPY_H
#define STRING_COPY_H


/*
  -[string_copy]-
  Copies string to destination
  takes:
 	rdi - address of string
 	rsi - address of buffer (destination)
 	rdx - length of buffer
  returns:
 	rax - buffers address if string was copied, NULL otherwise
*/

extern char *string_copy(char *, char *, long);

#endif /* STRING_COPY_H include guard */
