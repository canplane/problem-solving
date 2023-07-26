using namespace std;
#include <bits/stdc++.h>

#define MOD 1'000'000'000

int dp[101][10];

int main()
{
	int N;
	scanf("%d", &N);

	for (int j = 1; j <= 9; j++) {
		dp[1][j] = 1;
	}
	for (int i = 2; i <= N; i++) {
		dp[i][0] = dp[i - 1][1];
		for (int j = 1; j <= 8; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
		}
		dp[i][9] = dp[i - 1][8];
	}

	int ans = 0;
	for (int j = 0; j <= 9; j++) {
		ans = (ans + dp[N][j]) % MOD;
	}
	printf("%d", ans);
}