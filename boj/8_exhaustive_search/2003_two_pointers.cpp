#include <cstdio>

int A[10000], N, M;

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	int ans = 0, sum = 0, l = 0, r = 0;
	while (true) {
		if (sum == M) ans++;
		if (sum >= M) sum -= A[l++];
		else if (r == N) break;
		else sum += A[r++];
	}
	printf("%d", ans);
}