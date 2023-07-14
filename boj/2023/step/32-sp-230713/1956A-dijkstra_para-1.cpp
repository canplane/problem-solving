// 병렬 다익스트라 (병렬로 그리디 동작)
// 그냥 플로이드로 쓰면 O(V((E + V)logE)) > O(V^3: 플로이드)라 구림
// 이 코드는 연구용 코드: 다대다 최단거리 모두 구한 다음 최단 사이클 출력하는 건데 플로이드(120 ms)보다 3배 느림(330 ms)
// 그러나 병렬적으로 그리디를 유지하므로 최단 사이클(BOJ 1956 운동)을 빨리 검출하기엔 유용!

using namespace std;
#include <bits/stdc++.h>

#define INF ((1L << 31) - 1)

int main()
{
	int V, E;
	scanf("%d %d", &V, &E);

	vector<vector<pair<int, int>>> adj(V + 1);
	vector<vector<int>> dist(V + 1, vector<int>(V + 1, INF));
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

	while (E--) {
		int u, v, cost;
		scanf("%d %d %d", &u, &v, &cost);
		adj[u].push_back({ v, cost });
		pq.push({ dist[u][v] = cost, { u, v } });
	}

	int ans = INF;
	while (!pq.empty()) {
		auto [d, p] = pq.top(); pq.pop();
		auto [u, v] = p;
		if (dist[u][v] < d) {
			continue;
		}
		if (u == v) {	// cycle detection
			ans = min(ans, d);
		}
		for (auto [w, cost] : adj[v]) {
			if (d + cost < dist[u][w]) {
				pq.push({ dist[u][w] = d + cost, { u, w } });	
			}
		}
	}
	printf("%d", ans == INF ? -1 : ans);
}