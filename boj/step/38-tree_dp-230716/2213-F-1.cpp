using namespace std;
#include <cstdio>
#include <vector>
#include <algorithm>

int V, W[10001];
vector<int> adj[10001];
bool S[100001];

int indep[10001][2];
int dfs(int v, int u)
{
	// indep[cur_node: int][is_included: bool]
	indep[v][0] = 0, indep[v][1] = W[v];
	for (int w : adj[v]) {
		if (w == u) {
			continue;
		}
		indep[v][0] += dfs(w, v), indep[v][1] += indep[w][0];
	}
	S[v] = indep[v][0] < indep[v][1];	// 이건 틀린다. 부모가 포함되었냐 아니냐에 따라 지금 노드의 포함 여부가 다르거든.
	return max(indep[v][0], indep[v][1]);
}

int main()
{
	scanf("%d", &V);
	for (int i = 1; i <= V; i++) {
		scanf("%d", &W[i]);
	}
	for (int i = 0; i < V - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v), adj[v].push_back(u);
	}

	int ans = dfs(1, 0);
	printf("%d\n", ans);
	for (int i = 1; i <= V; i++) {
		if (S[i]) {
			printf("%d ", i);
		}
	}
}