using namespace std;
#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>

int V;
vector<pair<int, int>> adj[20001];

unsigned int dist[20001];
bool visit[20001];
void dijkstra(int u)
{
	memset(dist, -1, sizeof(dist));

	priority_queue<pair<unsigned int, int>, vector<pair<unsigned int, int>>, greater<>> pq;
	pq.push({ dist[u] = 0, u });
	while (!pq.empty()) {
		auto [d, u] = pq.top(); pq.pop();
		if (visit[u])
			continue;
		visit[u] = true;

		for (auto [v, w] : adj[u]) {
			if (!visit[v] && dist[u] + w < dist[v])
				pq.push({ dist[v] = dist[u] + w, v });
		}
	}
}

int main()
{
	int E, K;
	scanf("%d %d %d", &V, &E, &K);
	while (E--) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back({ v, w });
	}

	dijkstra(K);
	for (int i = 1; i <= V; i++) {
		if (dist[i] == -1)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
	}
}