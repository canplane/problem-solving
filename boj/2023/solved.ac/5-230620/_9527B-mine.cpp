#include <cstdio>

long f(long x, int i)
{
	long n = 1L << i;
	long xl = x / n * n;
	long xm = xl + n / 2;
	return xl / 2 + (xm <= x ? x - xm + 1 : 0);
}
int main()
{
	long A, B;
	scanf("%ld %ld", &A, &B);

	long cA = 0, cB = 0;
	for (int i = 1; i < 63; i++) {
		cA += f(A - 1, i), cB += f(B, i);
	}
	printf("%ld", cB - cA);
}