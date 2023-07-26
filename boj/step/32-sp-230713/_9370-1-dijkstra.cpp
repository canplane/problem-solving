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
int s;
int g, h;

bool passed[2001];

int dist[2001];
void dijkstra()
{
	for (int i = 1; i <= n; i++) {
		dist[i] = INF, passed[i] = false;
	}

	priority_queue<tuple<int, bool, int>, vector<tuple<int, bool, int>>, greater<>> pq;
	pq.push({ dist[s] = 0, true, s });
	while (!pq.empty()) {
		auto [d, not_passed, v] = pq.top(); pq.pop();
		if (dist[v] < d) {
			continue;
		}
		if (passed[v]) {
			continue;
		}
		passed[v] = !not_passed;

		for (auto [w, cost] : adj[v]) {
			if (d + cost <= dist[w]) {
				// 다익스트라 1번에 검출. 단 구현이 어려움. 그리디 요소를 생각해야 함.
				// not_passed가 false. 즉 지나쳐 지난 걸 먼저 뽑게 해야 함.
				pq.push({ dist[w] = d + cost, !(passed[v] || (v == g && w == h) || (v == h && w == g)), w });
			}
		}
	}
}
void sol()
{
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
	}

	for (int i = 0; i < t; i++) {
		scanf("%d", &goal[i]);
	}
	sort(goal, goal + t);

	dijkstra();

	for (int i = 0; i < t; i++) {
		if (passed[goal[i]]) {
			printf("%d ", goal[i]);
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