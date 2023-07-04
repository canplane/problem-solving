using namespace std;
#include <cstdio>
#include <vector>
#include <algorithm>

int V;
vector<int> adj[10001];

int dfn[10001], cnt;
vector<int> artis;
int dfs(int v, int u)
{
	int low = (dfn[v] = ++cnt), low_w;
	int nc = 0;
	bool is_arti = false;
	for (int w : adj[v]) {
		if (w == u) {
			continue;
		}
		if (dfn[w]) {	// back edge
			low = min(low, dfn[w]);
		}
		else {
			nc++, low_w = dfs(w, v);
			if (u != -1) {	// if not root
				is_arti |= (dfn[v] <= low_w);
			}
			low = min(low, low_w);
		}
	}
	if (u == -1) {	// if root
		is_arti = (nc > 1);
	}
	if (is_arti) {
		artis.push_back(v);
	}
	return low;
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

	sort(artis.begin(), artis.end());
	printf("%lu\n", artis.size());
	for (int v : artis) {
		printf("%d ", v);
	}
}