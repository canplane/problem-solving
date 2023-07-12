// 1st trial에서 dfn을 dist 비교로 수정해서 재방문하게 만들었더니 통과되었다.
// 이건 무슨 알고리즘이지?? 비효율적인거 같은데

using namespace std;
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

#define INF ((1L << 31) - 1)

#define MAX_N 400

vector<pair<int, int>> adj[MAX_N + 1];
int dist[MAX_N + 1];
bool finish[MAX_N + 1];
int ans;
void dfs(int v)
{
	for (auto [w, cost] : adj[v]) {
		if (dist[v] + cost < dist[w]) {
			dist[w] = dist[v] + cost, dfs(w);
		}
		else if (!finish[w]) {	// back edge -> cycle detect
			ans = min(ans, (dist[v] - dist[w]) + cost);
		}
	}
	finish[v] = true;
}
int sol()
{
	int N, M;
	scanf("%d %d", &N, &M);

	// init
	for (int v = 1; v <= N; v++) {
		adj[v].clear(), dist[v] = INF, finish[v] = false;
	}
	ans = INF;

	// set graph
	while (M--) {
		int x, y, cost;
		scanf("%d %d %d", &x, &y, &cost);
		adj[x].push_back({ y, cost });
	}

	// dfs
	for (int v = 1; v <= N; v++) {
		if (dist[v] == INF) {
			dist[v] = 0, dfs(v);
		}
	}
	return ans == INF ? -1 : ans;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		printf("#%d %d\n", tc, sol());
	}
}