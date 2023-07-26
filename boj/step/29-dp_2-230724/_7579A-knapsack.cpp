// BOJ 7579 G3 앱
// 3rd trial: dp + inverse (cost)
// 메모리의 범위가 넓으니 비용을 j의 기준으로 삼자.
// dp[i][j]: i번째까지의 앱을 이용했을 때 비용 j으로 확보할 수 있는 최대 메모리 양.

using namespace std;
#include <bits/stdc++.h>

int N, M;
int mem[101], cost[101];
int dp[101][10001];

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &mem[i]);
	}
	for (int i = 1; i <= N; i++) {
		scanf("%d", &cost[i]);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= 10000; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j >= cost[i]) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + mem[i]);
			}
		}
	}
	for (int j = 0; j <= 10000; j++) {
		if (dp[N][j] >= M) {
			printf("%d", j);
			break;
		}
	}
}