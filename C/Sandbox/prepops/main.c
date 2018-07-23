#include <stdio.h>

#define QUOTE(X) #X
#define GLUE(X,Y) QUOTE(X##Y) /* I can't do #X##Y compiler will throw an error */
#define P(X) puts(X);

int main(int argc, char* argv[])
{
	P(GLUE(Hello World, Mister))
	return 0;
}
