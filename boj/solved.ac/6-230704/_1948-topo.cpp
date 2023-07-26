using namespace std;
#include <cstdio>
#include <vector>
#include <utility>
#include <deque>

int N;
vector<pair<int, int>> adj[10001], adj_inv[10001];
int indeg[10001];
int dist[10001];
bool visit[10001];
int dfs(int u, int start)	// 간선 개수 세기
{
	if (visit[u]) {
		return 0;
	}
	visit[u] = true;	// 한 번 역추적된 것은 다시 조회되면 안 된다!
	int cnt = 0;
	for (auto [v, w] : adj_inv[u]) {
		if (dist[u] == dist[v] + w) {
			cnt += 1 + dfs(v, start);
		}
	}
	return cnt;
}

int main()
{
	int M;
	scanf("%d %d", &N, &M);
	while (M--) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back({ v, w });
		indeg[v]++;
	}
	int a, b;
	scanf("%d %d", &a, &b);

	deque<int> q;
	q.push_back(a);
	while (!q.empty()) {
		int u = q.front(); q.pop_front();
		for (auto [v, w] : adj[u]) {
			indeg[v] -= 1, dist[v] = max(dist[v], dist[u] + w);
			adj_inv[v].push_back({ u, w });
			if (!indeg[v]) {
				q.push_back(v);
			}
		}
	}
	printf("%d\n", dist[b]);
	printf("%d", dfs(b, a));
}