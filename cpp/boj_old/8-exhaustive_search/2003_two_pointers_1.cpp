#include <cstdio>

int A[10000], N, M, ans, sum, l, i;

int main() {
	scanf("%d %d", &N, &M);
	for (; i < N; i++) {
		scanf("%d", &A[i]);
		sum += A[i];
		while (sum > M) sum -= A[l++];
		if (sum == M) ans++;
	}
	printf("%d", ans);
}