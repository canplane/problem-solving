// lca (최소 공통 조상)

using namespace std;
#include <cstdio>
#include <vector>

int N;
vector<int> adj[50001];
int parent[50001], dep[50001];

void dfs(int v)
{
	for (int w : adj[v]) {
		if (!dep[w]) {
			parent[w] = v, dep[w] = dep[v] + 1;
			dfs(w);
		}
	}
}

int lca(int x, int y)
{	
	while (dep[x] > dep[y]) {
		x = parent[x];
	}
	while (dep[y] > dep[x]) {
		y = parent[y];
	}
	while (x != y) {
		x = parent[x], y = parent[y];
	}
	return x;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		adj[x].push_back(y), adj[y].push_back(x);
	}
	dep[1] = 1, dfs(1);

	int M;
	scanf("%d", &M);
	while (M--) {
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%d\n", lca(x, y));
	}
}
