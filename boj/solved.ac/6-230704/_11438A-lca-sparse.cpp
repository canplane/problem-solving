using namespace std;
#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX_N 100000
#define MAX_LOG_N 16	// floor(log_2 MAX_N)

int N;
vector<int> adj[MAX_N + 1];

int parent[MAX_N + 1][MAX_LOG_N + 1], dep[MAX_N + 1];
void dfs(int v, int u)
{
	parent[v][0] = u;
	for (int k = 1; k <= MAX_LOG_N; k++) {
		parent[v][k] = parent[parent[v][k - 1]][k - 1];
	}
	for (int w : adj[v]) {
		if (w != u) {
			dep[w] = dep[v] + 1;
			dfs(w, v);
		}
	}
}
int lca(int a, int b)
{
	if (dep[a] != dep[b]) {
		if (!(dep[a] > dep[b])) {
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

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b), adj[b].push_back(a);
	}
	dfs(1, 0);

	int M;
	scanf("%d", &M);
	while (M--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", lca(a, b));
	}
}