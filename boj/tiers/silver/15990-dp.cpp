using namespace std;
#include <cstdio>

#define MOD 1'000'000'009

long dp[1'000'001][4];

int main()
{
	dp[1][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1, dp[3][2] = 1, dp[3][3] = 1;
	for (int i = 4; i <= 1000000; i++) {
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
		dp[i][2] = (dp[i - 2][3] + dp[i - 2][1]) % MOD;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % MOD;
	}

	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		printf("%ld\n", (dp[n][1] + dp[n][2] + dp[n][3]) % MOD);
	}
}