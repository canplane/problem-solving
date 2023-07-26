#include <cstdio>
#include <algorithm>

unsigned int dp[5001], N;

int main()
{
	scanf("%d", &N);

	dp[1] = dp[2] = dp[4] = -1, dp[3] = dp[5] = 1;
	for (int i = 6; i <= N; i++) {
		dp[i] = std::min(dp[i - 3], dp[i - 5]);
		if (dp[i] != -1)	dp[i]++;
	}
	printf("%d", dp[N]);
}