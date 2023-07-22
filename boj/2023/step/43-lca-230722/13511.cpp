using namespace std;
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

#define MAX_N 100000
#define MAX_LOG_N 16	// floor(log_2 MAX_N)

int N;
vector<pair<int, long>> adj[MAX_N + 1];
int parent[MAX_N + 1][MAX_LOG_N + 1], dep[MAX_N + 1];
long dist[MAX_N + 1];

void dfs(int v, int u)
{
	parent[v][0] = u;
	for (int k = 1; k <= MAX_LOG_N; k++) {
		parent[v][k] = parent[parent[v][k - 1]][k - 1];
	}
	for (auto [w, cost] : adj[v]) {
		if (w != u) {
			dist[w] = dist[v] + cost, dep[w] = dep[v] + 1;
			dfs(w, v);
		}
	}
}
int lca(int a, int b)
{
	if (dep[a] != dep[b]) {
		if (dep[a] < dep[b]) {
			swap(a, b);
		}
		int dd = dep[a] - dep[b];
		for (int k = 0; k <= MAX_LOG_N; k++) {
			if (dd & (1 << k)) {
				a = parent[a][k];
			}
		}
	}
	if (a != b) {
		for (int k = MAX_LOG_N; k >= 0; k--) {
			if (parent[a][k] != parent[b][k]) {
				a = parent[a][k], b = parent[b][k];
			}
		}
		a = parent[a][0], b = parent[b][0];
	}
	return a;
}
int find_kth(int a, int b, int k)
{
	int r = lca(a, b);
	int da = dep[a] - dep[r], db = dep[b] - dep[r];
	if (k == da) {
		return r;
	}
	if (k > da) {
		k = (da + db) - k;
		swap(a, b);
	}
	for (int i = 0; i <= MAX_LOG_N; i++) {
		if (k & (1 << i)) {
			a = parent[a][i];
		}
	}
	return a;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back({ v, w }), adj[v].push_back({ u, w });
	}
	dfs(1, 0);

	int M;
	scanf("%d", &M);
	while (M--) {
		int i;
		scanf("%d", &i);
		if (i == 1) {
			int u, v;
			scanf("%d %d", &u, &v);
			printf("%ld\n", dist[u] + dist[v] - 2 * dist[lca(u, v)]);
		}
		else {
			int u, v, k;
			scanf("%d %d %d", &u, &v, &k);
			printf("%d\n", find_kth(u, v, k - 1));
		}
	}
}