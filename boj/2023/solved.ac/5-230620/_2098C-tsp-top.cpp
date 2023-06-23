using namespace std;
#include <cstdio>
#include <algorithm>

int N;
int W[16][16];

#define INF (1 << 30)
int dp[16][1 << 16];

// dp[current node][visited nodes up to now]: distance to node 0 by passing through left nodes
int dfs(int v, int visit)
{
	if (visit == (1 << N) - 1) {
		return W[v][0] != 0 ? W[v][0] : INF;
	}
	if (dp[v][visit]) {
		return dp[v][visit];
	}

	int tmp;
	dp[v][visit] = INF;
	for (int w = 0; w < N; w++) {
		if (visit & (1 << w)) {
			continue;
		}
		if (W[v][w] != 0 && (tmp = dfs(w, visit | (1 << w))) != INF) {
			dp[v][visit] = min(dp[v][visit], W[v][w] + tmp);
		}
	}
	return dp[v][visit];
}

int main()
{
	scanf("%d", &N);
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf("%d", &W[y][x]);
		}
	}
	printf("%d", dfs(0, 1 << 0));
}