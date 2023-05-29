using namespace std;
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

vector<pair<int, int>> adj[100001];
bool visit[100001];

int k;
int dfs(int v)
{
	int h1 = 0, h2 = 0;
	priority_queue<int> pq;
	pq.push(h1), pq.push(h2);

	visit[v] = true;
	for (auto [w, c] : adj[v]) {
		if (!visit[w]) {
			pq.push(c + dfs(w));
		}
	}
	h1 = pq.top(); pq.pop();
	h2 = pq.top(); pq.pop();
	k = max(k, h1 + h2);
	return h1;
}

int main()
{
	int V;
	scanf("%d", &V);
	for (int i = 0; i < V; i++) {
		int v, w, c;
		scanf("%d", &v);
		while (true) {
			scanf("%d", &w);
			if (w == -1)	break;
			scanf("%d", &c);
			adj[v].push_back({w, c}), adj[w].push_back({v, c});
		}
	}
	dfs(1);
	printf("%d", k);
}