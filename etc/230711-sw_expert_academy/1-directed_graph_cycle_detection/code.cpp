// weighted directed graph cycle detection

using namespace std;
#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>

#define INF 0x7fffffff

#define MAX_N 400
vector<pair<int, int>> adj[MAX_N + 1];	// adjacency list

int dist[MAX_N + 1];
int dfn[MAX_N + 1], max_dfn;
bool finish[MAX_N + 1];
int dfs(int v)
{
	int ret = INF;
	dfn[v] = ++max_dfn;
	for (auto [w, cost] : adj[v]) {
		if (!dfn[w]) {	// unvisit
			dist[w] = dist[v] + cost;
			ret = min(ret, dfs(w));
		}
		else if (!finish[w]) {	// dfn이 있는데, finish는 아니다. -> back edge
			// cycle detect
			ret = min(ret, (dist[v] - dist[w]) + cost);
		}
	}
	finish[v] = true;
	return ret;
}

int sol()
{
	int N, M;
	scanf("%d %d", &N, &M);
	while (M--) {
		int x, y, cost;
		scanf("%d %d %d", &x, &y, &cost);
		adj[x].push_back({ y, cost });
	}
	int ans = INF;
	for (int v = 1; v <= N; v++) {
		if (!dfn[v]) {
			ans = min(ans, dfs(v));
		}
	}
	return ans == INF ? -1 : ans;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		// clear
		for (int i = 1; i <= MAX_N; i++) {
			adj[i].clear();
		}
		memset(dist, 0, sizeof(dist));
		memset(dfn, 0, sizeof(dfn)), max_dfn = 0;
		memset(finish, 0, sizeof(finish));

		printf("#%d %d\n", tc, sol());
	}
}