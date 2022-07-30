#include <stdio.h>

union X {
	char h;
	int k;
	float f;
} U = { .k = 0xFFF1 };

int main(void) {
	printf("%d\n%d\n%f\n",U.h,U.k,U.f);
	U.h = 0;
	printf("%d\n%d\n%f\n",U.h,U.k,U.f);
	U.f = 3;
	printf("%d\n%d\n%f\n",U.h,U.k,U.f);
}
