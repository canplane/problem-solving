// same as BOJ 2748, 10870

#include <cstdio>

long f[91];

int main()
{
	f[0] = 0, f[1] = 1;
	for (int i = 2; i <= 90; i++)
		f[i] = f[i - 1] + f[i - 2];

	int n;
	scanf("%d", &n);
	printf("%ld", f[n]);
}