using namespace std;
#include <cstdio>
#include <vector>
#include <tuple>
#include <queue>

int V, E;
vector<tuple<int, int>> adj[10001];

// prim : O(ElgE) = O(ElgV) (advantageous for DENSE graphs)
vector<tuple<int, int, int>> mst;
bool visit[10001];
void prim(int u)
{
	priority_queue<tuple<int, int, int>> pq;
	for (int i = 0; i < V - 1; i++) {
		visit[u] = true;
		for (auto [v, cost] : adj[u]) {
			if (!visit[v]) {
				pq.push({ -cost, -u, -v });
			}
		}
		while (true) {
			auto [cost, _u, v] = pq.top(); pq.pop();
			cost = -cost, _u = -_u, v = -v;
			if (!visit[v]) {
				mst.push_back({ _u, v, cost });
				u = v;
				break;
			}
		}
	}
}

// main
int main()
{
	scanf("%d %d", &V, &E);
	int u, v, cost;
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &u, &v, &cost);
		adj[u].push_back({ v, cost }), adj[v].push_back({ u, cost });
	}

	prim(1);

	int ans = 0;
	for (auto [u, v, cost] : mst) {
		ans += cost;
	}
	printf("%d", ans);
}