#include <bits/stdc++.h>
using namespace std;

const int N_MAX = 1e9;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int V, E; cin >> V >> E;
	vector<vector<pair<int, int>>> graph(V+1); // {node, distance};
	vector<vector<int>> dist(V+1, vector<int>(V+1, N_MAX));
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq; // {distance, start, end}

	while (E--) {
		int a, b, c; cin >> a >> b >> c;
		graph[a].push_back({b, c});
		pq.push({c, a, b});
	}

	while (!pq.empty()) {
		auto [distance, start, end] = pq.top(); pq.pop();

		if (start == end) {cout << distance; return 0;}
		if (dist[start][end] < distance) continue;

		for (auto [nxtNode,nxtDist] : graph[end]) {
			if (dist[start][nxtNode] <= distance + nxtDist) continue;
			dist[start][nxtNode] = distance + nxtDist;
			pq.push({dist[start][nxtNode], start, nxtNode});
		}
	}
	cout << -1;
	return 0;
}