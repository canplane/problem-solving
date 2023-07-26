// 이항계수 2 : 파스칼의 삼각형

#include <cstdio>

int binom[1001][1001];

int main()
{
	binom[0][0] = 1;
	for (int n = 1; n <= 1000; n++) {
		binom[n][0] = binom[n][n] = 1;
		for (int r = 1; r < n; r++) {
			binom[n][r] = (binom[n - 1][r - 1] + binom[n - 1][r]) % 10007;
		}
	}

	int N, K;
	scanf("%d %d", &N, &K);
	printf("%d", binom[N][K]);
}