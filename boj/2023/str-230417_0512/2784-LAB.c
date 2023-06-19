#include	<stdio.h>
#include	<string.h>
#define		N				3
#define		N2				(N + N)
#define		SWAP(x, y)		(&(x) != &(y) && ((y) ^= (x), (x) ^= (y), (y) ^= (x)))

char A[N2][N + 1], B[N][N + 1], S[N][N + 1];

int p[N2];
/*void __debug()
{
	int i;
	for (i = 0; i < N2; i++)	printf("%d", p[i]);
	printf(": ");
	for (i = 0; i < N; i++)	printf("%s ", A[p[i]]);
	puts("");
}*/
int permut(int r_i, int b)
{
	int i, j, c;
	if (r_i == N2) {
		for (i = 0; i < N; i++)
			strcpy(B[i], A[p[i]]);
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				if (A[p[N + i]][j] != B[j][i])		return 0;
		
		c = 0;
		for (i = 0; i < N && !(c = strcmp(S[i], B[i])); i++);
		if (!b || c == 1)
			for (i = 0; i < N; i++)	strcpy(S[i], B[i]);
		return 1;
	}

	for (i = r_i; i < N2; i++) {
		SWAP(p[r_i], p[i]);
		b |= permut(r_i + 1, b);
		SWAP(p[r_i], p[i]);
	}
	return b;
}

int main()
{
	int i;
	for (i = 0; i < N2; i++)		scanf("%s", A[i]), p[i] = i;

	if (permut(0, 0))
		for (i = 0; i < N; i++)	puts(S[i]);
	else
		puts("0");
}