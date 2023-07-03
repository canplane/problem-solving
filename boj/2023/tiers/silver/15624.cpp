#include <cstdio>

#define MOD 1'000'000'007

long f[1000001];

int main()
{
	f[0] = 0, f[1] = 1;
	for (int i = 2; i <= 1000000; i++)
		f[i] = (f[i - 1] + f[i - 2]) % MOD;

	int n;
	scanf("%d", &n);
	printf("%ld", f[n]);
}