#ifndef EXTERN_H
#define EXTERN_H

// Both forward declarations work without extern,
// for functions always (no matter the extern keyword) aslong no function body is present,
// for variables it'll be forward declaration if its preceeded by a extern keyword and/or when
// the variable declaration is not in the same statement initialized but it must be defined (with initializer) somewhere else,
// if its not defined somewhere else, a variables without the extern keyword will be taken as definition.
// Also a variabled declaration with a preceeding "extern" and with initialization will be taken as variable definition,
// rendering the use of the "extern" keyword useless
extern void func(char*);
extern char* storage;

#endif /* EXTERN_H */
