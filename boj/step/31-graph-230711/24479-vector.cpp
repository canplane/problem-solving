#include <cstdio>
#include <vector>
#include <algorithm>

int N, R;
std::vector<int> adj[100001];

int dfn[100001], max_dfn;
void dfs(int u)
{
	dfn[u] = ++max_dfn;
	for (int v : adj[u])
		if (!dfn[v])
			dfs(v);
}

int main()
{
	int M, u, v;
	scanf("%d %d %d", &N, &M, &R);
	while (M--) {
		scanf("%d %d", &u, &v);
		adj[u].push_back(v), adj[v].push_back(u);
	}
	for (int i = 1; i <= N; i++)
		std::sort(adj[i].begin(), adj[i].end());
	dfs(R);
	for (int i = 1; i <= N; i++)
		printf("%d\n", dfn[i]);
}