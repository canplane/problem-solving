// O(V(V + E)logE)

using namespace std;
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

#define INF ((1L << 31) - 1)
#define MAX_N 400
vector<pair<int, int>> adj[MAX_N + 1];

int N, M;
long D[MAX_N + 1][MAX_N + 1];
void dijkstra(vector<pair<int, long>> adj[], int start)
{
	for (int u = 1; u <= N; u++) {
		D[start][u] = INF;
	}

	priority_queue<pair<long, int>, vector<pair<long, int>>, greater<>> pq;
	
	pq.push({ D[start][start] = 0, start });
	while (!pq.empty()) {
		auto [d, u] = pq.top(); pq.pop();
		if (D[start][u] < d) {
			continue;
		}
		for (auto [v, cost] : adj[u]) {
			if (d + cost < D[start][v]) {
				pq.push({ D[start][v] = d + cost, v });
			}
		}
	}
}
long sol()
{
	scanf("%d %d", &N, &M);

	vector<pair<int, long>> adj[N + 1];

	long ans = INF;
	while (M--) {
		int x, y; long cost;
		scanf("%d %d %ld", &x, &y, &cost);
		if (x == y) {
			ans = min(ans, cost);
		}
		else {
			adj[x].push_back({ y, cost });
		}
	}

	// dijkstra for all nodes
	for (int u = 1; u <= N; u++) {
		dijkstra(adj, u);
	}

	// get minimum cycle
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != j) {
				ans = min(ans, D[i][j] + D[j][i]);
			}
		}
	}
	return (ans == INF) ? -1 : ans;
}

int main()
{
	printf("%d", sol());
}