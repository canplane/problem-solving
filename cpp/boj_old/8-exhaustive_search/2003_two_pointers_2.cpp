#include <cstdio>

int A[10000], N, M, ans, sum, *l = A, *r = A;

int main() {
	scanf("%d %d", &N, &M);
	while (r < A + N) {
		scanf("%d", r);
		sum += *(r++);
		while (sum > M) sum -= *(l++);
		if (sum == M) ans++;
	}
	printf("%d", ans);
}