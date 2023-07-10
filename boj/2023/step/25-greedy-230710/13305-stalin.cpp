// 짜고 보니 스탈린 정렬

#include <cstdio>

int N;
long X[100000], C[100000];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++) {
		scanf("%ld", &X[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%ld", &C[i]);
	}

	long c = C[0], ans = C[0] * X[0];
	for (int i = 1; i < N - 1; i++) {
		if (C[i] < c) {
			c = C[i];
		}
		ans += c * X[i];
	}
	printf("%ld", ans);
}