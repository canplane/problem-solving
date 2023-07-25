// BOJ 11049 G3 행렬 곱셈 순서
// matrix chain multiplication (연쇄 행렬 곱셈)

using namespace std;
#include <bits/stdc++.h>

int N;
int d[501];
int dp[501][501];

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &d[i - 1], &d[i]);
	}

	for (int di = 1; di <= N - 1; di++) {
		int j;
		for (int i = 1; (j = i + di) <= N; i++) {
			dp[i][j] = INT_MAX;
			for (int k = i; k + 1 <= j; k++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + d[i - 1] * d[k] * d[j]);
			}
		}
	}
	printf("%d", dp[1][N]);
}