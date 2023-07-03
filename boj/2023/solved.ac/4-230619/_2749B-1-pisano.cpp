using namespace std;
#include <cstdio>

#define MOD 1'000'000

// if divider is n = 10^k -> period = 1.5 * 10^k
#define PISANO (MOD / 10 * 15)
long dp[PISANO + 1];

int main()
{
	long n;
	scanf("%ld", &n);

	dp[0] = 0, dp[1] = 1;
	for (int i = 2; i <= PISANO; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	}
	printf("%ld", dp[n % PISANO]);
}