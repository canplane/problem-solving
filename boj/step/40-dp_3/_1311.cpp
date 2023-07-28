using namespace std;
#include <bits/stdc++.h>

int N;
int D[20][20];

int dp[21][1 << 20];
int bt(int i, int vis)
{
	if (dp[i][vis]) {
		return dp[i][vis];
	}

	if (i == N) {
		return dp[i][vis] = 0;
	}
	int ret = INT_MAX;
	for (int j = 0; j < N; j++) {
		if (!(vis & (1 << j))) {
			ret = min(ret, D[i][j] + bt(i + 1, vis | (1 << j)));
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
	printf("%d", bt(0, 0));
}