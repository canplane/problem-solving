using namespace std;
#include <bits/stdc++.h>

int N, M;
vector<int> adj[100001];

vector<vector<int>> sccs;
stack<int> st;
bool is_scc[100001];
int dfn[100001], max_dfn;
int tarjan(int v)
{
	st.push(v);
	int low = (dfn[v] = ++max_dfn);
	for (int w : adj[v]) {
		if (!dfn[w]) {
			low = min(low, tarjan(w));
		}
		else if (!is_scc[w]) {
			low = min(low, dfn[w]);
		}
	}
	if (low == dfn[v]) {
		sccs.push_back({}); auto &scc = sccs.back();
		while (true) {
			int w = st.top(); st.pop();
			is_scc[w] = true;
			scc.push_back(w);
			if (w == v) {
				break;
			}
		}
	}
	return low;
}

bool vis[100001];
void dfs(int v) {
	vis[v] = true;
	for (int w : adj[v]) {
		if (!vis[w]) {
			dfs(w);
		}
	}
}

void sol()
{
	for (int v = 1; v < 100001; v++) {
		adj[v].clear();
	}
	sccs.clear();
	memset(is_scc, 0, sizeof(is_scc));
	memset(dfn, 0, sizeof(dfn)), max_dfn = 0;
	memset(vis, 0, sizeof(vis));

	scanf("%d %d", &N, &M);

	while (M--) {
		int x, y;
		scanf("%d %d", &x, &y);
		adj[x].push_back(y);
	}

	for (int v = 1; v <= N; v++) {
		if (!dfn[v]) {
			tarjan(v);
		}
	}

	int cnt = 0;
	for (auto it = sccs.rbegin(); it != sccs.rend(); it++) {
		int v = it->back();
		if (!vis[v]) {
			++cnt, dfs(v);
		}
	}
	printf("%d\n", cnt);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		sol();
	}
}