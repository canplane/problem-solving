// BOJ 2482 G3 색상환

using namespace std;
#include <bits/stdc++.h>

#define MOD 1000000003

int N, K;
long dp[1000][1000];
int main()
{
	scanf("%d %d", &N, &K);

	dp[0][0] = dp[1][0] = 1;
	dp[1][1] = 2;
	for (int i = 2; i < N; i++) {
		dp[i][0] = 1;
		for (int j = 1; j < i; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % MOD;
		}
	}
	// N - 1번지를 포함했을 때, 하지 않았을 때
	printf("%ld", (dp[N - 3][K - 1] + dp[N - 2][K]) % MOD);
}