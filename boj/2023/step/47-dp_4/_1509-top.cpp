#include <bits/stdc++.h>

char s[2501];
int N;
bool palin[2500][2500];

int dp[2501];	// dp 안 하면 시간 초과!! (dfs에 dp 해야 한다.)
int dfs(int i)
{
	if (dp[i] || i == N)	return dp[i];

	int ret = INT_MAX;
	for (int j = i; j < N; j++)
		if (palin[i][j])
			ret = std::min(ret, 1 + dfs(j + 1));
	return dp[i] = ret;
}

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
	printf("%d", dfs(0));
}