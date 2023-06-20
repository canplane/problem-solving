#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int N, M;
		scanf("%d %d", &N, &M);
		
		if (M - N < N) {
			N = M - N;
		}

		long ans = 1;
		for (int i = 0; i < N; i++) {
			ans *= (M - i);
		}
		for (int i = 0; i < N; i++) {
			ans /= (N - i);
		}
		printf("%ld\n", ans);
	}
}