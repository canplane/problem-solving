using namespace std;
#include <cstdio>
#include <vector>
#include <tuple>
#include <queue>

// disjoint set for kruskal
int parent[10001];
void dj_init(int n)
{
	for (int v = 1; v <= n; v++) {
		parent[v] = v;
	}
}
int dj_find(int v)
{
	int r = v;
	while (parent[r] != r) {
		r = parent[r];
	}
	int t;
	while ((t = parent[v]) != v) {
		parent[v] = r;
		v = t;
	}
	return r;
}
void dj_union(int u, int v)
{
	int ru = dj_find(u), rv = dj_find(v);
	parent[rv] = ru;
}

// kruskal : O(ElgE) = O(ElgV) (advantageous for SPARSE graphs)
int V, E;
priority_queue<tuple<int, int, int>> pq;
vector<tuple<int, int, int>> mst;
void kruskal()
{
	dj_init(V);
	while (!pq.empty()) {
		auto [cost, u, v] = pq.top(); pq.pop();
		cost = -cost, u = -u, v = -v;
		if (dj_find(u) == dj_find(v))
			continue;
		mst.push_back({ u, v, cost }), dj_union(u, v);
	}
}

// main
int main()
{
	scanf("%d %d", &V, &E);
	int u, v, cost;
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &u, &v, &cost);
		pq.push({ -cost, -u, -v });
	}

	kruskal();

	int ans = 0;
	for (auto [u, v, cost] : mst) {
		ans += cost;
	}
	printf("%d", ans);
}