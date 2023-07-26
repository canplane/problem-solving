using namespace std;
#include <cstdio>
#include <vector>
#include <deque>
#include <cstring>
#include <algorithm>

#define MAX_NODES 1000
vector<int> adj[1 + MAX_NODES];

bool visit[1 + MAX_NODES];

void dfs(int v)
{
	visit[v] = true;
	// PRE
	printf("%d ", v);
	for (auto w : adj[v]) {
		if (!visit[w]) {
			dfs(w);
			// IN
		}
	}
	// POST
}
void bfs(int v)
{
	deque<int> q;
	visit[v] = true, q.push_back(v);
	while (q.size()) {
		v = q.front(), q.pop_front();
		// PRE
		printf("%d ", v);
		for (auto w : adj[v]) {
			if (!visit[w])
				visit[w] = true, q.push_back(w);
		}
	}
}

int main()
{
	int N, M, V;
	scanf("%d %d %d", &N, &M, &V);

	for (int i = 1; i <= M; i++) {
		int v, w;
		scanf("%d %d", &v, &w);
		adj[v].push_back(w), adj[w].push_back(v);
	}
	for (int i = 1; i <= N; i++) {
		sort(adj[i].begin(), adj[i].end());
	}

	dfs(V), printf("\n");
	memset(visit, 0, N + 1);
	bfs(V), printf("\n");
}