// 순방향/역방향 그래프 2개에 대해 다익스트라. 그리고 합산 중 min

using namespace std;
#include <bits/stdc++.h>

void dijkstra(int dist[], int N, vector<pair<int, int>> adj[], int u)
{
	for (int i = 1; i <= N; i++) {
		dist[i] = 1 << 30;
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ dist[u] = 0, u });
	while (!pq.empty()) {
		auto [d, u] = pq.top(); pq.pop();
		if (dist[u] < d) {
			continue;
		}
		for (auto [v, cost] : adj[u]) {
			if (d + cost < dist[v]) {
				pq.push({ dist[v] = d + cost, v });
			}
		}
	}
}

int N, M, X;
vector<pair<int, int>> adj[1001], adj_inv[1001];
int dist[1001], dist_inv[1001];

int main()
{
	scanf("%d %d %d", &N, &M, &X);
	while (M--) {
		int a, b, cost;
		scanf("%d %d %d", &a, &b, &cost);
		adj[a].push_back({ b, cost }), adj_inv[b].push_back({ a, cost });
	}

	dijkstra(dist, N, adj, X), dijkstra(dist_inv, N, adj_inv, X);
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		ans = max(ans, dist[i] + dist_inv[i]);
	}
	printf("%d", ans);
}