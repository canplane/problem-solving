using namespace std;
#include <cstdio>
#include <algorithm>

int N, d[501];

int dp[501][501];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &d[i], &d[i + 1]);
	}

	for (int i = 1; i <= N; i++) {
		dp[i][i] = 0;
	}
	for (int n = 1; n <= N - 1; n++) {
		int j;
		for (int i = 1; (j = i + n) <= N; i++) {
			dp[i][j] = 0x7ffffff;
			for (int k = i; k + 1 <= j; k++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + (d[i - 1] * d[k] * d[j]));
			}
		}
	}
	printf("%d", dp[1][N]);
}