// 병렬 다익스트라 (병렬로 그리디 동작)
// 그냥 플로이드로 쓰면 O(V((E + V)logE)) > O(V^3: 플로이드)라 구림.
// 그리고 각각 다익스트라 하는 것보다도 느림. (아마 heap이 커져서 삽입/삭제가 더 느린 문제인 듯.)
// 이 코드는 연구용 코드 (플로이드를 이걸로 대체하기). 실제로도 플로이드보다 느림.
// 그러나 병렬적으로 그리디를 유지하므로 최단 사이클(BOJ 1956 운동)을 빨리 검출하기엔 유용!

using namespace std;
#include <bits/stdc++.h>

#define INF ((1L << 31) - 1)

vector<pair<int, int>> adj[101];
int dist[101][101];

int main()
{
	int V, E;
	scanf("%d %d", &V, &E);

	for (int u = 1; u <= V; u++) {
		for (int v = 1; v <= V; v++) {
			dist[u][v] = u == v ? 0 : INF;
		}
	}

	priority_queue<pair<int, pair<int, int>>> pq;
	while (E--) {
		int u, v, cost;
		scanf("%d %d %d", &u, &v, &cost);
		if (cost < dist[u][v]) {
			adj[u].push_back({ v, cost });
			pq.push({ -(dist[u][v] = cost), { u, v } });
		}
	}

	while (!pq.empty()) {
		auto [d, p] = pq.top(); pq.pop();
		auto [u, v] = p;
		d = -d;
		if (dist[u][v] < d) {
			continue;
		}
		for (auto [w, cost] : adj[v]) {
			if (d + cost < dist[u][w]) {
				pq.push({ -(dist[u][w] = d + cost), { u, w } });	
			}
		}
	}

	for (int u = 1; u <= V; u++) {
		for (int v = 1; v <= V; v++) {
			printf("%d ", (dist[u][v] < INF) * dist[u][v]);
		}
		printf("\n");
	}
}