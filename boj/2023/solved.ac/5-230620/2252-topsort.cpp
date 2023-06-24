// topological sorting (위상 정렬)

using namespace std;
#include <cstdio>
#include <vector>
#include <deque>

int N;
vector<int> adj[32001];
int indeg[32001];

deque<int> q;

int main()
{
	int M;
	scanf("%d %d", &N, &M);
	while (M--) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		indeg[v] += 1;
	}

	for (int u = 1; u <= N; u++) {
		if (indeg[u] == 0) {
			q.push_back(u);
		}
	}
	while (!q.empty()) {
		int u = q.front(); q.pop_front();
		printf("%d ", u);
		for (int v : adj[u]) {
			indeg[v] -= 1;
			if (indeg[v] == 0) {
				q.push_back(v);
			}
		}
	}
}