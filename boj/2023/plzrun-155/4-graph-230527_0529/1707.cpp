using namespace std;
#include <cstdio>
#include <vector>
#include <deque>
#include <utility>
#include <cstring>

bool bfs(vector<int> adj[], int visit[], int v)
{
	deque<pair<int, int>> q;
	visit[v] = 1, q.push_back({ v, 1 });
	while (q.size()) {
		auto [v, c] = q.front(); q.pop_front();
		for (int w : adj[v]) {
			if (!visit[w])
				visit[w] = -c, q.push_back({ w, -c });
			else if (visit[w] == c)
				return false;
		}
	}
	return true;
}

int main()
{
	int K;
	scanf("%d", &K);
	while (K--) {
		int V, E;
		scanf("%d %d", &V, &E);

		vector<int> adj[1 + V];

		while (E--) {
			int u, v;
			scanf("%d %d", &u, &v);
			adj[u].push_back(v), adj[v].push_back(u);
		}
		
		int visit[1 + V];
		memset(visit, 0, (1 + V) * sizeof(int));

		bool ans = true;
		for (int v = 1; v <= V; v++) {
			if (!visit[v])
				ans &= bfs(adj, visit, v);
		}
		printf("%s\n", ans ? "YES" : "NO");
	}
}