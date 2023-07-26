// negative cycle이 존재하면 YES

using namespace std;
#include <bits/stdc++.h>
#define INF ((1L << 30) - 1)

int N;
vector<pair<int, int>> adj[501];
int dist[501];

void clear()
{
	for (int i = 0; i < 501; i++) {
		adj[i].clear();
		dist[i] = INF;
	}
}
bool sol()
{
	int M, W;
	scanf("%d %d %d", &N, &M, &W);
	while (M--) {
		int a, b, cost;
		scanf("%d %d %d", &a, &b, &cost);
		adj[a].push_back({ b, cost }), adj[b].push_back({ a, cost });
	}
	while (W--) {
		int a, b, cost;
		scanf("%d %d %d", &a, &b, &cost);
		adj[a].push_back({ b, -cost });
	}

	dist[1] = 0;
	for (int k = 0; k < N - 1; k++) {
		for (int u = 1; u <= N; u++) {
			for (auto [v, cost] : adj[u]) {
				dist[v] = min(dist[v], dist[u] + cost);
			}
		}
	}
	for (int u = 1; u <= N; u++) {
		for (auto [v, cost] : adj[u]) {
			if (dist[u] + cost < dist[v]) {
				return true;
			}
		}
	}
	return false;
}
int main()
{
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		clear(), printf("%s\n", sol() ? "YES" : "NO");
	}
}