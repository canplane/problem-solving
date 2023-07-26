// lca (최소 공통 조상) + prefix sum (누적 합) : 788 ms -> 504 ms

using namespace std;
#include <cstdio>
#include <vector>
#include <utility>

int N;
vector<pair<int, int>> adj[40001];

int parent[40001], dep[40001], dist[40001];
void dfs(int v, int u, int d)
{
	for (auto [w, cost] : adj[v]) {
		if (w == u) {
			continue;
		}
		parent[w] = v, dep[w] = d + 1, dist[w] = dist[v] + cost;
		dfs(w, v, d + 1);
	}
}
int lca(int a, int b)
{
	int ans = dist[a] + dist[b];
	while (dep[a] < dep[b]) {
		b = parent[b];
	}
	while (dep[a] > dep[b]) {
		a = parent[a];
	}
	while (a != b) {
		a = parent[a], b = parent[b];
	}
	return ans - 2 * dist[a];
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++) {
		int a, b, cost;
		scanf("%d %d %d", &a, &b, &cost);
		adj[a].push_back({ b, cost }), adj[b].push_back({ a, cost });
	}
	parent[1] = 0, dep[1] = 0, dist[1] = 0;
	dfs(1, -1, 0);

	int M;
	scanf("%d", &M);
	while (M--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", lca(a, b));
	}
}