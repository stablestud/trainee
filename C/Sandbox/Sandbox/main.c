#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <limits.h>
#include <stdalign.h>

int main(void)
{
	int iVar = 5;
	int aVar = iVar + iVar++;
	printf("%d\n", aVar);

	return 0;
}
