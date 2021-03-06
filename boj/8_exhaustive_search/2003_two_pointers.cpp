/*
두 포인터를 조작하여 부분합을 구할 수 있는 이유는 배열의 값이 자연수이기 때문.
자연수이므로 end를 증가시키면 부분합이 증가하고, start를 증가시키면 부분합이 감소하는 것을 보장할 수 있다.
음수가 섞여 있다면 이를 보장할 수 없으므로 two pointers를 사용할 수 없다.

시간 복잡도 : O(2n) = O(n)
 */

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