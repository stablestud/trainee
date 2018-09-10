#include <stdio.h>

int main(void)
{
	char chessfield[8][8] = {
		{ 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' },
		{ 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
		{ },
		{ },
		{ },
		{ },
		{ 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
		{ 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
	};

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
			printf("%c", chessfield[i][j] );
		puts("");
	}

	return 0;
}
