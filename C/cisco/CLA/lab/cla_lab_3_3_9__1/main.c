#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	float val;
	if (scanf("%f", &val ) != 1)
		abort();

	switch ( (int)val ) {
	case 1:
		puts("Very bad.");
		break;
	case 2:
		puts("Bad.");
		break;
	case 3:
		puts("Neutral Bad.");
		break;
	case 4:
		puts("Good.");
		break;
	case 5:
		puts("Very good.");
		break;
	}

	return 0;
}
