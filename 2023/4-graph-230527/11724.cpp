using namespace std;
#include <cstdio>
#include <vector>

int N, M;
vector<int> adj[1001];

bool visit[1001];

void dfs(int v)
{
	visit[v] = true;
	for (int w : adj[v]) {
		if (!visit[w]) {
			dfs(w);
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i++) {
		int v, w;
		scanf("%d %d", &v, &w);
		adj[v].push_back(w), adj[w].push_back(v);
	}

	int ans = 0;
	for (int v = 1; v <= N; v++) {
		if (!visit[v]) {
			ans++;
			dfs(v);
		}
	}
	printf("%d", ans);
}