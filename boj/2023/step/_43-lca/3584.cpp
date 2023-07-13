using namespace std;
#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX_N 100000

int N;
vector<int> adj[MAX_N + 1];

int parent[MAX_N + 1], dep[MAX_N + 1];
void dfs(int v, int u)
{
	for (int w : adj[v]) {
		if (w != u) {
			dep[w] = dep[v] + 1;
			dfs(w, v);
		}
	}
}
int lca(int a, int b)
{
	while (dep[a] > dep[b]) {
		a = parent[a];
	}
	while (dep[b] > dep[a]) {
		b = parent[b];
	}
	while (a != b) {
		a = parent[a], b = parent[b];
	}
	return a;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			adj[i].clear();
			parent[i] = dep[i] = 0;
		}

		for (int i = 0; i < N - 1; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			adj[a].push_back(b), parent[b] = a;
		}
		int r = 1;
		while (parent[r]) {
			r = parent[r];
		}
		dfs(r, 0);

		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", lca(a, b));
	}
}