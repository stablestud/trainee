#include <stdio.h>

int cmpmat(int *mat0, int *mat1, int matsize);
int evalmat(int *mat0, int *mat1, int matsize);

int main(void)
{
	int mat0[9] = {
		1, 3, 9,
		5, 8, 9,
		1, 7, 3
	};

	int mat1[9] = {
		1, 3, 9,
		5, 8, 9,
		1, 7, 3
	};

	return evalmat( mat0, mat1, 9 );
}

int evalmat(int *mat0, int *mat1, int matsize)
{
	int ret;

	if ((ret = cmpmat( mat0, mat1, matsize ))) {
		if (ret == 1)
			puts("First matrice is greater than the second one.");
		else
			puts("Second matrice is greater than the first one.");
	} else 
		puts("Both matrices are equal.");

	return ret;
}

int cmpmat(int *mat0, int *mat1, int matsize)
{
	for (int i = 0; i < matsize; i++) {
		if ( mat0[i] != mat1[i] ) {
			if ( mat0[i] > mat1[i] )
				return 1;
			else
				return -1;
		}
	}

	return 0;
}
