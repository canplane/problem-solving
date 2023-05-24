#include <stdio.h>

int A, B, m;
void f(int n)
{
	int r = n % B;
	if ((n /= B))	f(n);
	printf("%d ", r);
}

int main()
{
	scanf("%d %d %d", &A, &B, &m);
	
	int N = 0, d;
	while (m--) {
		scanf("%d", &d);
		N = N * A + d;
	}
	f(N);
}