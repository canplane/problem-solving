#include <cstdio>

int N, K;
int S[100001];

int main()
{
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &S[i]);
		S[i] += S[i - 1];
	}

	int ans = S[K] - S[0];
	for (int i = K + 1; i <= N; i++) {
		if (ans < S[i] - S[i - K]) {
			ans = S[i] - S[i - K];
		}
	}
	printf("%d", ans);
}