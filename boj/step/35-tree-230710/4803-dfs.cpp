using namespace std;
#include <cstdio>
#include <vector>

int n;
vector<int> adj[501];

bool visit[501], is_tree;
void dfs(int v, int u)
{
	visit[v] = true;
	
	for (int w : adj[v]) {
		if (visit[w]) {
			if (w != u) {
				is_tree = false;
			}
			continue;
		}
		dfs(w, v);
	}
}

int main()
{
	for (int nth = 1; ; nth++) {
		int m;
		scanf("%d %d", &n, &m);
		if (n == 0) {
			break;
		}

		for (int i = 1; i <= n; i++) {
			adj[i].clear(), visit[i] = false;
		}
		while (m--) {
			int a, b;
			scanf("%d %d", &a, &b);
			adj[a].push_back(b), adj[b].push_back(a);
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (!visit[i]) {
				is_tree = true, dfs(i, 0);
				cnt += is_tree;
			}
		}
		printf("Case %d: ", nth);
		if (cnt == 0) {
			printf("No trees.\n");
		}
		else if (cnt == 1) {
			printf("There is one tree.\n");
		}
		else {
			printf("A forest of %d trees.\n", cnt);
		}
	}
}