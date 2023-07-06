using namespace std;
#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX_N 100001
#define MAX_LOG_N 16

int N;
vector<int> adj[MAX_N];

int dep[MAX_N], parent[MAX_N][MAX_LOG_N];
void dfs(int v, int u, int d)
{
	dep[v] = d;
	parent[v][0] = u;
	for (int k = 0; k < MAX_LOG_N - 1; k++) {
		parent[v][k + 1] = parent[parent[v][k]][k];
	}
	
	for (int w : adj[v]) {
		if (w == u) {
			continue;
		}
		dfs(w, v, d + 1);
	}
}
int lca(int a, int b)
{
	int k;
	if (dep[a] != dep[b]) {
		if (!(dep[a] > dep[b])) {
			swap(a, b);
		}
		int dd = dep[a] - dep[b];
		for (k = 0; (1 << k) <= dd; k++) {
			if (dd & (1 << k)) {
				a = parent[a][k];
			}
		}
	}
	if (a != b) {
		for (k = MAX_LOG_N - 1; k >= 0; k--) {
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
	dfs(1, 0, 1);

	int M;
	scanf("%d", &M);
	while (M--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", lca(a, b));
	}
}