// 가장 먼 노드: https://school.programmers.co.kr/learn/courses/30/lessons/49189

using namespace std;
#include <bits/stdc++.h>

vector<int> adj[20001];
int dist[20001];

int solution(int n, vector<vector<int>> edge) {
	for (auto p : edge) {
		adj[p[0]].push_back(p[1]), adj[p[1]].push_back(p[0]);
	}
	
	int max_d = 0;
	deque<pair<int, int>> q;
	q.push_back({ 1, dist[1] = 1 });
	while (!q.empty()) {
		auto [v, d] = q.front(); q.pop_front();
		max_d = max(max_d, d);
		for (int w : adj[v]) {
			if (!dist[w]) {
				q.push_back({ w, dist[w] = d + 1 });
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += (dist[i] == max_d);
	}
	return ans;
}