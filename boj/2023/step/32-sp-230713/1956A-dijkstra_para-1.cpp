// 병렬 다익스트라 (병렬로 그리디 동작)
// 그냥 플로이드로 쓰면 O(V((E + V)logE)) > O(V^3: 플로이드)라 구림.
// 그리고 각각 다익스트라 하는 것보다도 느림. (아마 heap이 커져서 삽입/삭제가 더 느린 문제인 듯.)
// 이 코드는 연구용 코드: 다대다 최단거리 모두 구한 다음 최단 사이클 출력하는 건데 플로이드(120 ms)보다 3배 느림(330 ms)
// 그러나 병렬적으로 그리디를 유지하므로 최단 사이클(BOJ 1956 운동)을 빨리 검출하기엔 유용!

using namespace std;
#include <bits/stdc++.h>

#define INF ((1L << 31) - 1)
#define MAX_V 400

vector<pair<int, int>> adj[MAX_V + 1];
int D[MAX_V + 1][MAX_V + 1];

priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

int main()
{
	int V, E;
	scanf("%d %d", &V, &E);
	
	for (int u = 1; u <= V; u++) {
		for (int v = 1; v <= V; v++) {
			D[u][v] = INF;
		}
	}

	while (E--) {
		int u, v, cost;
		scanf("%d %d %d", &u, &v, &cost);
		adj[u].push_back({ v, cost });
		pq.push({ D[u][v] = cost, { u, v } });
	}

	int ans = INF;
	while (!pq.empty()) {
		auto [d, p] = pq.top(); pq.pop();
		auto [u, v] = p;
		if (D[u][v] < d) {
			continue;
		}
		if (u == v) {	// cycle detection
			ans = min(ans, d);
		}
		for (auto [w, cost] : adj[v]) {
			if (d + cost < D[u][w]) {
				pq.push({ D[u][w] = d + cost, { u, w } });	
			}
		}
	}
	printf("%d", ans == INF ? -1 : ans);
}