using namespace std;
#include <cstdio>
#include <vector>

int N;
vector<int> adj[100001];

int dep[100001], parent[100001][17];
void dfs(int v, int u, int d)
{
	dep[v] = d;
	parent[v][0] = u;
	for (int k = 1; k < 17; k++) {
		parent[v][k] = parent[parent[v][k - 1]][k - 1];
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
	while (dep[a] < dep[b]) {
		for (k = 0; k < 16; k++) {
			if (dep[parent[b][k + 1]] <= dep[a]) {
				break;
			}
		}
		b = parent[b][k];
	}
	while (dep[b] < dep[a]) {
		for (k = 0; k < 16; k++) {
			if (dep[parent[a][k + 1]] <= dep[b]) {
				break;
			}
		}
		a = parent[a][k];
	}
	while (a != b) {
		for (k = 0; k < 16; k++) {
			if (parent[a][k + 1] == parent[b][k + 1]) {
				break;
			}
		}
		a = parent[a][k], b = parent[b][k];
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
	dfs(1, 0, 0);

	int M;
	scanf("%d", &M);
	while (M--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", lca(a, b));
	}
}