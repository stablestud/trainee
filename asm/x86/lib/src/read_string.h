
#ifndef READ_STRING_H
#define READ_STRING_H


/*
  -[read_string]-
  Read a string of fixed maximum size from stdin, removes \n from the end
  takes:
        rdi - buffer address to save the string to plus space for \0 sign
        rsi - size of the buffer
  returns:
        rax - returns buffer starting address
*/

extern char *read_string(char const*, long); 

#endif /* READ_STRING_H include guard */
