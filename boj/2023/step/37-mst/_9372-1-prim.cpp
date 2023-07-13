// prim은 pq에 점 집어넣기 : pair<cost, point>

using namespace std;
#include <cstdio>
#include <vector>
#include <utility>
#include <queue>

int N;
vector<pair<int, int>> adj[1001];

bool vis[1001];
int prim(int v)
{
	int ans = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0, v });
	while (!pq.empty()) {
		auto [cost, v] = pq.top(); pq.pop();
		if (vis[v]) {
			continue;
		}
		ans += cost;
		vis[v] = true;
		for (auto [w, cost_w] : adj[v]) {
			if (vis[w]) {
				continue;
			}
			pq.push({ cost_w, w });
		}
	}
	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int M;
		scanf("%d %d", &N, &M);
		for (int i = 1; i <= N; i++) {
			adj[i].clear();
			vis[i] = 0;
		}

		while (M--) {
			int a, b;
			scanf("%d %d", &a, &b);
			adj[a].push_back({ b, 1 }), adj[b].push_back({ a, 1 });
		}
		printf("%d\n", prim(1));
	}
}