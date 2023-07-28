using namespace std;
#include <bits/stdc++.h>

int N;
int D[20][20];

int dp[21][1 << 20];
int bt(int i, int cost, int vis)
{
	if (dp[i][vis]) {
		return dp[i][vis];
	}

	if (i == N) {
		return dp[i][vis] = cost;
	}
	int ret = INT_MAX;
	for (int j = 0; j < N; j++) {
		if (!(vis & (1 << j))) {
			// Failed: cost가 점점 증가하는 식으로 백트래킹하면 dp 배열이 최솟값이 되지 못한다.
			ret = min(ret, bt(i + 1, cost + D[i][j], vis | (1 << j)));
		}
	}
	return dp[i][vis] = ret;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &D[i][j]);
		}
	}
	printf("%d", bt(0, 0, 0));
}