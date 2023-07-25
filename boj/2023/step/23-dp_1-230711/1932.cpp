using namespace std;
#include <bits/stdc++.h>

int N;
int A[501][501];
int dp[501][501];

int main()
{
	scanf("%d", &N);
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= y; x++) {
			scanf("%d", &A[y][x]);
		}
	}
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= y; x++) {
			dp[y][x] = A[y][x] + max(dp[y - 1][x], dp[y - 1][x - 1]);
		}
	}
	int ans = dp[N][1];
	for (int x = 1; x <= N; x++) {
		ans = max(ans, dp[N][x]);
	}
	printf("%d", ans);
}