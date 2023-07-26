using namespace std;
#include <bits/stdc++.h>
#define INF ((1L << 30) - 1)

int N;
int adj[16][16];
int dp[16][1 << 16];

int dfs(int v, int vis)
{
	if (dp[v][vis]) {
		return dp[v][vis];
	}
	if (vis == (1 << N) - 1) {
		return dp[v][vis] = adj[v][0] ? adj[v][0] : INF;
	}
	int ret = INF;
	for (int w = 0; w < N; w++) {
		if (!(vis & (1 << w)) && adj[v][w]) {
			ret = min(ret, adj[v][w] + dfs(w, vis | (1 << w)));
		}
	}
	return dp[v][vis] = ret;
}

int main()
{
	scanf("%d", &N);
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf("%d", &adj[y][x]);
		}
	}
	printf("%d", dfs(0, 1 << 0));
}