
#define QUOTE(X) (#X)
#define GLUE(X,Y) QUOTE(X##Y) /* I can't do #X##Y compiler will throw an error */

#if defined __cplusplus
#       include <iostream>
#       define PRINT(X) std::cout << #X << std::endl;
#       define COMPILER 2
#       define COMPL    CPP
#else
#       include <stdio.h>
#       define PRINT(X) puts(#X);
#       define COMPILER 1
#       define COMPL    C
#endif

#if (COMPILER == 2)
#       warning CPP
#elif (COMPILER == 1)
#       warning C
#else
#       warning OTHER
#endif

#define P(X) PRINT(X)

int main(int argc, char* argv[])
{
	P(COMPL)
	return 0;
}
