// 트리: A, B, C 다 푸는데 한시간

using namespace std;
#include <bits/stdc++.h>

int N, M;
vector<int> adj[200001];
bool vis[200001];
int levels[200001];

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v), adj[v].push_back(u);
	}

	deque<pair<int, int>> q;
	vis[1] = true, q.push_back({ 1, 1 });
	while (!q.empty()) {
		auto [u, d] = q.front(); q.pop_front();
		levels[d]++;
		for (int v : adj[u]) {
			if (!vis[v]) {
				vis[v] = true, q.push_back({ v, d + 1 });
			}
		}
	}
	
	long ans = 1;
	for (int i = 1; i < 200001; i++) {
		if (!levels[i]) {
			break;
		}
		ans = (ans * (1 + levels[i])) % 1'000'000'007;
	}
	ans -= 1;
	printf("%ld", ans);
}