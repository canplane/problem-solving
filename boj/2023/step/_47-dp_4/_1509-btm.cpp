// dfs 메모이제이션 말고 타뷸레이션에 익숙해지자.

#include <bits/stdc++.h>

char s[2501];
int N;
bool palin[2500][2500];

int dp[2501];

int main()
{
	scanf("%s", s);

	palin[0][0] = true;
	for (N = 1; s[N]; N++)
		palin[N][N] = palin[N][N - 1] = true;

	for (int k = 1; k < N; k++)
		for (int i = 0; i + k < N; i++)
			if (palin[i + 1][i + k - 1] && s[i] == s[i + k])
				palin[i][i + k] = true;

	for (int i = N - 1; i >= 0; i--) {
		dp[i] = INT_MAX;
		for (int j = i; j < N; j++)
			if (palin[i][j])
				dp[i] = std::min(dp[i], 1 + dp[j + 1]);
	}
	printf("%d", dp[0]);
}