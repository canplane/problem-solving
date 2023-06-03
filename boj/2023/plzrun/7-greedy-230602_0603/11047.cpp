using namespace std;
#include <cstdio>

int N, K;
int A[10];

int main()
{
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	long ans = 0;
	for (int i = N - 1; i >= 0; i--) {
		ans += K / A[i];
		K %= A[i];
		if (K == 0) break;
	}
	printf("%ld", ans);
}