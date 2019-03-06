
#ifndef STRING_LENGTH_H
#define STRING_LENGTH_H


/*
  -[string_length]-
  Counts the length of a string till \0 sign
  takes:
        rdi - address of string
  returns:
        rax - size of the string counted excluding \0 sign
*/

extern long string_length(char *);

#endif /* STRING_LENGTH_H include guard */
