// [28 mins]
// 노드마다 가중치 포함하냐 안하냐와 최대 가중치 계산은 쉬웠는데, 역추적이 오래 걸림

using namespace std;
#include <bits/stdc++.h>

int V, W[10001];
vector<int> adj[10001];

int indep[10001][2];	// [node][is_included]
int dfs(int v, int u)
{
	indep[v][0] = 0, indep[v][1] = W[v];
	for (int w : adj[v])
		if (w != u)
			indep[v][0] += dfs(w, v), indep[v][1] += indep[w][0];
	return max(indep[v][0], indep[v][1]);
}

vector<int> S;
void trace(int v, int u, bool is_u_indep)
{
	if ((is_u_indep = !is_u_indep && indep[v][0] < indep[v][1]))
		S.push_back(v);

	for (int w : adj[v])
		if (w != u)
			trace(w, v, is_u_indep);
}

int main()
{
	scanf("%d", &V);
	for (int u = 1; u <= V; u++)
		scanf("%d", &W[u]);
	for (int i = 0; i < V - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v), adj[v].push_back(u);
	}

	int ans = dfs(1, 0);
	printf("%d\n", ans);

	trace(1, 0, false);
	sort(begin(S), end(S));
	for (int v : S)
		printf("%d ", v);
}