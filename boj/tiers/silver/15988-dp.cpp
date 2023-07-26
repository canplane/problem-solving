using namespace std;
#include <cstdio>

#define MOD 1'000'000'009

long dp[1'000'001];

int main()
{
	dp[0] = 1;
	dp[1] = dp[0];
	dp[2] = dp[1] + dp[0];
	dp[3] = dp[2] + dp[1] + dp[0];
	for (int i = 4; i <= 1000000; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
	}

	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		printf("%ld\n", dp[n]);
	}
}