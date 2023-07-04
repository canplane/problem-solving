using namespace std;
#include <cstdio>
#include <vector>
#include <algorithm>

int V;
vector<int> adj[10001];

int dfn[10001], low[10001], cnt;
bool arti[10001];
void dfs(int v, int u)
{
	low[v] = dfn[v] = ++cnt;
	int nc = 0;
	for (int w : adj[v]) {
		if (w == u) {
			continue;
		}
		if (dfn[w]) {	// back edge
			low[v] = min(low[v], dfn[w]);
		}
		else {
			nc++;
			dfs(w, v);
			if (u != -1) {	// if not root
				arti[v] |= (dfn[v] <= low[w]);
			}
			low[v] = min(low[v], low[w]);
		}
	}
	if (u == -1) {	// if root
		arti[v] = (nc > 1);
	}
}

int main()
{
	int E;
	scanf("%d %d", &V, &E);
	while (E--) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v), adj[v].push_back(u);
	}

	for (int i = 1; i <= V; i++) {
		if (!dfn[i]) {
			dfs(i, -1);
		}
	}

	vector<int> ans;
	for (int i = 1; i <= V; i++) {
		if (arti[i]) {
			ans.push_back(i);
		}
	}
	printf("%lu\n", ans.size());
	for (int v : ans) {
		printf("%d ", v);
	}
}