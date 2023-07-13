// 시간 성능 : tree > prim > kruskal 

using namespace std;
#include <cstdio>
#include <vector>
#include <utility>

int N;
vector<int> adj[1001];

int parent[1001];
int dfs(int v, int u)
{
	parent[v] = u;

	int ret = 0;
	for (int w : adj[v]) {
		if (!parent[w]) {
			ret += 1 + dfs(w, v);
		}
	}
	return ret;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int M;
		scanf("%d %d", &N, &M);
		for (int i = 1; i <= N; i++) {
			adj[i].clear();
			parent[i] = 0;
		}

		while (M--) {
			int a, b;
			scanf("%d %d", &a, &b);
			adj[a].push_back(b), adj[b].push_back(a);
		}
		printf("%d\n", dfs(1, -1));
	}
}