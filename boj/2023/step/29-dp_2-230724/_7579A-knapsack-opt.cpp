// BOJ 7579 G3 앱
// 3rd trial: dp + inverse (cost)
// 2차원 배열이 사실 필요가 없다!

using namespace std;
#include <bits/stdc++.h>

int N, M;
int mem[101], cost[101];
int dp[10001];

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
		for (int j = 10000; j >= cost[i]; j--) {
			dp[j] = max(dp[j], dp[j - cost[i]] + mem[i]);
		}
	}
	for (int j = 0; j <= 10000; j++) {
		if (dp[j] >= M) {
			printf("%d", j);
			break;
		}
	}
}