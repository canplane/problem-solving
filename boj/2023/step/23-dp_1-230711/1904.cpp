#include <cstdio>

int N;
int A[1000001];

int main()
{
	scanf("%d", &N);

	A[0] = A[1] = 1;
	for (int i = 2; i <= N; i++) {
		A[i] = (A[i - 1] + A[i - 2]) % 15746;
	}
	printf("%d", A[N]);
}