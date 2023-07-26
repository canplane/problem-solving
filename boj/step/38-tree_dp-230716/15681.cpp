using namespace std;
#include <cstdio>
#include <vector>

int N, R;
vector<int> adj[100001];
int tree_sz[100001];

int dfs(int v, int u)
{
	tree_sz[v] = 1;
	for (int w : adj[v]) {
		if (w == u) {
			continue;
		}
		tree_sz[v] += dfs(w, v);
	}
	return tree_sz[v];
}

int main()
{
	int Q;
	scanf("%d %d %d", &N, &R, &Q);
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v), adj[v].push_back(u);
	}
	dfs(R, 0);

	while (Q--) {
		int u;
		scanf("%d", &u);
		printf("%d\n", tree_sz[u]);
	}
}