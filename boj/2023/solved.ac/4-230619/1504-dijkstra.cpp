using namespace std;
#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>

int N;
vector<pair<int, int>> adj[801];

unsigned int dist[801];
bool visit[801];
void dijkstra(int u, int goal)
{
	memset(dist, -1, sizeof(dist));
	memset(visit, 0, sizeof(visit));

	priority_queue<pair<unsigned int, int>, vector<pair<unsigned int, int>>, greater<>> pq;
	pq.push({ dist[u] = 0, u });
	while (!pq.empty()) {
		auto [d, u] = pq.top(); pq.pop();
		if (visit[u])
			continue;
		visit[u] = true;
		if (u == goal)
			return;
		for (auto [v, w] : adj[u]) {
			if (!visit[v] && d + w < dist[v]) {
				pq.push({ dist[v] = d + w, v });
			}
		}
	}
}
unsigned int f(int v1, int v2)
{
	dijkstra(v1, v2);
	unsigned int b = dist[v2];
	if (b == -1)
		return -1;

	// 1 .. v1 .. v2 .. N
	dijkstra(1, -1);
	unsigned int a1 = dist[v1], a2 = dist[v2];
	// 1 .. v2 .. v1 .. N	
	dijkstra(N, -1);
	unsigned int c1 = dist[v2], c2 = dist[v1];

	unsigned int ans1 = (a1 != -1 && c1 != -1) ? a1 + b + c1 : -1;
	unsigned int ans2 = (a2 != -1 && c2 != -1) ? a2 + b + c2 : -1;
	return min(ans1, ans2);
}

int main()
{
	int E;
	scanf("%d %d", &N, &E);
	while (E--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		adj[a].push_back({ b, c }), adj[b].push_back({ a, c });
	}

	int v1, v2;
	scanf("%d %d", &v1, &v2);
	printf("%d", f(v1, v2));
}