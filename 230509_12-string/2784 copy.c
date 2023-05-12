#include	<stdio.h>
#include	<string.h>
#define		SWAP(x, y)		(&x != &y && (y ^= x, x ^= y, y ^= x))

char A[6][4], B[3][4], S[3][4];

int p[6];
int permut(int pos, int b)
{
	int i, j, c;
	if (pos == 6) {
		for (i = 0; i < 3; i++)
			memcpy(B[i], A[p[i]], 4);
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				if (A[p[3 + i]][j] != B[j][i])		return 0;
		
		c = 0;
		for (i = 0; i < 3 && !(c = strcmp(S[i], B[i])); i++);
		if (!b || c == 1)
			for (i = 0; i < 3; i++)	memcpy(S[i], B[i], 4);
		return 1;
	}

	for (i = pos; i < 6; i++) {
		SWAP(p[pos], p[i]);
		b |= permut(pos + 1, b);
		SWAP(p[pos], p[i]);
	}
	return b;
}

int main()
{
	int i;
	for (i = 0; i < 6; i++)		scanf("%s", A[i]), p[i] = i;

	if (permut(0, 0))
		for (i = 0; i < 3; i++)	puts(S[i]);
	else
		puts("0");
}