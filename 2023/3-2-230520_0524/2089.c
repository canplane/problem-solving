#include <stdio.h>

void f(int n)
{
	int r = !!(n % (-2));
	if ((n = (n - r) / (-2)))	f(n);
	printf("%d", r);
}

int main()
{
	int N;
	scanf("%d", &N);
	f(N);
}