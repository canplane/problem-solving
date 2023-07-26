using namespace std;
#include <cstdio>
#include <queue>
#include <cstring>

bool adj[1001][1001];
int N, M, V;

bool visit[1001];
void dfs(int v)
{
	visit[v] = true;
	printf("%d ", v);
	for (int w = 1; w <= N; w++) {
		if (adj[v][w] && !visit[w]) {
			dfs(w);
		}
	}
}
void bfs(int v)
{
	queue<int> q;
	visit[v] = true, q.push(v);
	while (q.size()) {
		v = q.front(), q.pop();
		printf("%d ", v);
		for (int w = 1; w <= N; w++) {
			if (adj[v][w] && !visit[w]) {
				visit[w] = true, q.push(w);
			}
		}
	}
	printf("\n");
}


int main()
{
	scanf("%d %d %d", &N, &M, &V);

	for (int i = 1; i <= M; i++) {
		int v, w;
		scanf("%d %d", &v, &w);
		adj[v][w] = adj[w][v] = true;
	}

	dfs(V), printf("\n");
	memset(visit, 0, N + 1), bfs(V);
}