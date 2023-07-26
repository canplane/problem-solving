// lca (최소 공통 조상)

using namespace std;
#include <cstdio>
#include <vector>
#include <tuple>

int N;
vector<tuple<int, int>> adj[40001];

tuple<int, int, int> parent[40001];
void dfs(int v, int u, int level)
{
	for (auto [w, cost] : adj[v]) {
		if (w == u) {
			continue;
		}
		parent[w] = { v, level + 1, cost }, dfs(w, v, level + 1);
	}
}
int lca(int a, int b)
{
	int dist = 0;
	while (get<1>(parent[a]) < get<1>(parent[b])) {
		dist += get<2>(parent[b]);
		b = get<0>(parent[b]);
	}
	while (get<1>(parent[a]) > get<1>(parent[b])) {
		dist += get<2>(parent[a]);
		a = get<0>(parent[a]);
	}
	while (a != b) {
		dist += get<2>(parent[a]) + get<2>(parent[b]);
		a = get<0>(parent[a]), b = get<0>(parent[b]);
	}
	return dist;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++) {
		int a, b, cost;
		scanf("%d %d %d", &a, &b, &cost);
		adj[a].push_back({ b, cost }), adj[b].push_back({ a, cost });
	}
	parent[1] = { -1, 0, 0 }, dfs(1, -1, 0);

	int M;
	scanf("%d", &M);
	while (M--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", lca(a, b));
	}
}