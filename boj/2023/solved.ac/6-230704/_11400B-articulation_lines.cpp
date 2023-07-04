using namespace std;
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

int V;
vector<int> adj[100001];

int dfn[100001], cnt;
vector<pair<int, int>> artis;
int dfs(int v, int u)
{
	int low = (dfn[v] = ++cnt), low_w;
	for (int w : adj[v]) {
		if (w == u) {
			continue;
		}
		if (dfn[w]) {	// back edge
			low = min(low, dfn[w]);
		}
		else {
			low_w = dfs(w, v);
			if (dfn[v] < low_w) {
				pair<int, int> p = { v, w };
				if (p.first > p.second) {
					swap(p.first, p.second);
				}
				artis.push_back(p);
			}
			low = min(low, low_w);
		}
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
	for (auto [v, w] : artis) {
		printf("%d %d\n", v, w);
	}
}