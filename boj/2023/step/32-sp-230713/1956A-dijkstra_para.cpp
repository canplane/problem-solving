// 병렬 다익스트라 (병렬로 그리디 동작)
// @7bellaa : https://www.acmicpc.net/source/63336356
// https://www.acmicpc.net/board/view/121766
// 저도 그 모 회사 문제로 고민하다가 이 문제를 먼저 풀게 되었는데 플로이드-워셜로 풀었더니 시간초과 떴고, 우선순위 큐 사용해서 아래와 같이 구현했더니 65ms로 통과됐습니다. https://www.acmicpc.net/source...

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

	int ans = -1;
	while (!pq.empty()) {
		auto [d, p] = pq.top(); pq.pop();
		auto [u, v] = p;
		if (D[u][v] < d) {
			continue;
		}
		if (u == v) {	// cycle detection
			ans = d;
			break;
		}
		for (auto [w, cost] : adj[v]) {
			if (d + cost < D[u][w]) {
				pq.push({ D[u][w] = d + cost, { u, w } });	
			}
		}
	}
	printf("%d", ans);
}