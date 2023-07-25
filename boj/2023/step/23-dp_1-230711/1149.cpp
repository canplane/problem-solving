using namespace std;
#include <bits/stdc++.h>

int N;
int dp[1001][3];

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int r, g, b;
		scanf("%d %d %d", &r, &g, &b);
		dp[i][0] = r + min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = g + min(dp[i - 1][2], dp[i - 1][0]);
		dp[i][2] = b + min(dp[i - 1][0], dp[i - 1][1]);
	}
	printf("%d", min(min(dp[N][0], dp[N][1]), dp[N][2]));
}