// [7 mins]

using namespace std;
#include <cstdio>
#include <vector>
#include <deque>

int N, M;
vector<int> adj[32001];
int indeg[32001];

int main()
{
	scanf("%d %d", &N, &M);
	while (M--) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
	}
	for (int u = 1; u <= N; u++) {
		for (int v : adj[u]) {
			indeg[v]++;
		}
	}

	deque<int> q;
	for (int u = 1; u <= N; u++) {
		if (indeg[u] == 0) {
			q.push_back(u);
		}
	}
	while (!q.empty()) {
		int u = q.front(); q.pop_front();
		printf("%d ", u);
		for (int v : adj[u]) {
			if (--indeg[v] == 0) {
				q.push_back(v);
			}
		}
	}
}