#include <cstdio>

int N;
int dp[1000001];

int main()
{
	scanf("%d", &N);

	dp[0] = dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}
	printf("%d", dp[N]);
}