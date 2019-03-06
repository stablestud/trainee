
#ifndef STRING_TO_INT_H
#define STRING_TO_INT_H

/*
  -[string_to_int]-
  parse a string containing a signed number to an signed integer
  takes:
        rdi - string address to read from, string must be terminated with \0
  returns:
        rax - signed integer value, -1 on failure
*/

extern int string_to_int(char const*);

#endif /* STRING_TO_INT_H include guard */
