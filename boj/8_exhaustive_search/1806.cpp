#include <cstdio>

int A[99999], N, S, sum, ans = 100000;

int main() {
	scanf("%d %d", &N, &S);

	for (int l = 0, r = 0; r < N; r++) {
		scanf("%d", &A[r]);
		if ((sum += A[r]) >= S) {
			while ((sum -= A[l++]) >= S);
			if (r - l + 2 < ans)
				ans = r - l + 2;
		}
	}
	printf("%d", (ans != 100000) * ans);
}