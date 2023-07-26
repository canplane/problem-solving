// BOJ 2098 G1 외판원 순회
// vis를 dfs 몸통 부분에서 잠시 넣었다 빼는 버전

using namespace std;
#include <bits/stdc++.h>
#define INF ((1L << 30) - 1)

int N;
int adj[16][16];
int dp[16][1 << 17];

int dfs(int v, int vis)
{
	if (dp[v][vis]) {
		return dp[v][vis];
	}

	int ret = INF;
	vis |= (1 << v);
	if (vis == (1 << N) - 1) {
		return adj[v][0] ? adj[v][0] : INF;
	}
	for (int w = 0; w < N; w++) {
		if (!(vis & (1 << w)) && adj[v][w]) {
			ret = min(ret, adj[v][w] + dfs(w, vis));
		}
	}
	vis &= ~(1 << v);
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
	printf("%d", dfs(0, 0));
}