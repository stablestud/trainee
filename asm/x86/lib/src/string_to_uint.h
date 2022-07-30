
#ifndef STRING_TO_UINT_H
#define STRUNG_TO_UINT_H

/*
  -[string_to_uint]-
  parse a string containing a unsigned number to an unsigned integer
  takes:
        rdi - string address to read from, string must be terminated with \0
  returns:
        rax - unsigned integer value, -1 on failure
*/

extern int string_to_uint(char const*);

#endif /* STRING_TO_UINT_H include guard */
