#include <cstdio>

int N;
int A[100001];

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	int da = A[1] - A[0];
	for (int i = 2; i < N; i++) {
		da = gcd(da, A[i] - A[i - 1]);
	}
	printf("%d", ((A[N - 1] - A[0]) / da + 1) - N);
}