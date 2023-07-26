// [60 mins]
// 다익스트라 3번에 검출. 구현이 쉬움

using namespace std;
#include <cstdio>
#include <vector>
#include <tuple>
#include <queue>
#include <cstring>
#include <algorithm>

#define INF ((1L << 31) - 1)

int n;
vector<tuple<int, int>> adj[2001];
int goal[2001], t;
int s, g, h;

int D[2001][2001];
void dijkstra(int start)
{
	for (int i = 1; i <= n; i++) {
		D[start][i] = INF;
	}

	priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<>> pq;
	pq.push({ D[start][start] = 0, start });
	while (!pq.empty()) {
		auto [d, v] = pq.top(); pq.pop();
		if (D[start][v] < d) {
			continue;
		}

		for (auto [w, cost] : adj[v]) {
			if (d + cost < D[start][w]) {
				pq.push({ D[start][w] = d + cost, w });
			}
		}
	}
}
void sol()
{
	int l;

	int m;
	scanf("%d %d %d", &n, &m, &t);
	scanf("%d %d %d", &s, &g, &h);

	for (int i = 1; i <= n; i++) {
		adj[i].clear();
	}
	while (m--) {
		int a, b, d;
		scanf("%d %d %d", &a, &b, &d);
		adj[a].push_back({ b, d }), adj[b].push_back({ a, d });
		if ((a == g && b == h) || (a == h && b == g)) {
			l = d;
		}
	}
	dijkstra(s), dijkstra(g), dijkstra(h);

	for (int i = 0; i < t; i++) {
		scanf("%d", &goal[i]);
	}
	sort(goal, goal + t);

	for (int i = 0; i < t; i++) {
		int x = goal[i];
		if (D[s][x] == D[s][g] + l + D[h][x] || D[s][x] == D[s][h] + l + D[g][x]) {
			printf("%d ", x);
		}
	}
	printf("\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		sol();
	}
}