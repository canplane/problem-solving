using namespace std;
#include <cstdio>
#include <vector>
#include <deque>
#include <utility>
#include <queue>

int n;
vector<pair<int, int>> adj[1001];

#define INF 0x7fffffff
bool visit[1001];
int dist[1001], pre[1001];
template <class T>
struct cmp {	// greater
	bool operator()(const T& u, const T& v) const {
		return dist[u] > dist[v];
	}
};
void dijkstra(int u)
{
	for (int i = 0; i < 1001; i++) {
		dist[i] = INF;
	}

	priority_queue<int, vector<int>, cmp<int>> pq;

	dist[u] = 0;
	pq.push(u);
	while (!pq.empty()) {
		int u = pq.top(); pq.pop();
		if (visit[u]) {
			continue;
		}
		visit[u] = true;

		for (auto [v, w] : adj[u]) {
			if (!visit[v] && dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w, pre[v] = u;
				pq.push(v);
			}
		}
	}
}

int main()
{
	int m;
	scanf("%d %d", &n, &m);
	while (m--) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back({ v, w });
	}

	int A, B;
	scanf("%d %d", &A, &B);
	dijkstra(A);
	printf("%d\n", dist[B]);

	deque<int> path;
	for (int u = B; u != A; u = pre[u]) {
		path.push_front(u);
	}
	path.push_front(A);
	printf("%ld\n", path.size());
	for (int u : path) {
		printf("%d ", u);
	}
}