#include <cstdio>

int sum[10001], N, M, tmp;

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		sum[i + 1] = sum[i] + tmp;
	}
	int ans = 0;
	for (int i = 0; i < N + 1; i++)
		for (int j = i + 1; j < N + 1; j++)
			ans += (sum[j] - sum[i] == M);
	printf("%d", ans);
}