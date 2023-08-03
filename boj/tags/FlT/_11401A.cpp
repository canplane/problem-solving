// Fermat's little Theorem (페르마의 소정리)
// (prime p) & (not p | a) => a^(p - 1) = 1 (mod p)
// if b / a = x (mod p), then b * a^(p - 1) = x * 1 (mod p)

#include <cstdio>

#define P 1000000007
int nPk(int n, int k)
{
	long x = 1;
	while (k--)
		x = (x * (n--)) % P;
	return x;
}
int po(int a, int n)
{
	if (n == 0)
		return 1;
	long x = po(a, n / 2);
	x = (x * x) % P;
	if (n % 2)
		x = (x * a) % P;
	return x;
}
int binom(int n, int k)
{
	if (k > n - k)
		k = n - k;
	long nu = nPk(n, k), de = nPk(k, k);
	return (nu * po(de, P - 2)) % P;
}

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	printf("%d", binom(N, K));
}