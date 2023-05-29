using namespace std;
#include <cstdio>
#include <vector>

vector<int> adj[100001];
int parent[100001];

void dfs(int v)
{
	for (int w : adj[v])
		if (!parent[w])
			parent[w] = v, dfs(w);
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int v, w;
		scanf("%d %d", &v, &w);
		adj[v].push_back(w), adj[w].push_back(v);
	}
	parent[1] = -1, dfs(1);
	for (int v = 2; v <= N; v++)	printf("%d\n", parent[v]);
}