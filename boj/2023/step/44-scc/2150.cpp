// Tarjan's algorithm

using namespace std;
#include <bits/stdc++.h>

int V;
vector<int> adj[10001];

deque<int> st;
vector<vector<int>> sccs;
int scn[10001], max_scn;

int dfn[10001], max_dfn;
int dfs(int v, int u)
{
	int ret = dfn[v] = ++max_dfn;
	st.push_back(v);
	for (int w: adj[v]) {
		if (!dfn[w])
			ret = min(ret, dfs(w, v));
		else if (!scn[w])
			ret = min(ret, dfn[w]);
	}
	if (ret == dfn[v]) {
		++max_scn;
		sccs.push_back({}); auto &scc = sccs.back(); 
		while (true) {
			int w = st.back(); st.pop_back();
			scn[w] = max_scn;
			scc.push_back(w);
			if (w == v)
				break;
		}
		sort(scc.begin(), scc.end());
	}
	return ret;
}

int main()
{
	int E;
	scanf("%d %d", &V, &E);
	while (E--) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
	}
	
	for (int v = 1; v <= V; v++)
		if (!dfn[v])
			dfs(v, 0);
	sort(sccs.begin(), sccs.end());

	printf("%d\n", max_scn);
	for (auto scc : sccs) {
		for (auto v : scc)
			printf("%d ", v);
		printf("-1\n");
	}
}