using namespace std;
#include <cstdio>
#include <vector>

int N;
vector<int> adj[101];
bool visit[101];

int dfs(int u)
{
	int cnt = 1;
	visit[u] = true;
	for (int v : adj[u]) {
		if (!visit[v])
			cnt += dfs(v);
	}
	return cnt;
}
int main()
{
	scanf("%d", &N);
	
	int M;
	scanf("%d", &M);
	while (M--) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v), adj[v].push_back(u);
	}

	printf("%d", dfs(1) - 1);
}