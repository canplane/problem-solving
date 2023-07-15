/*

4 -> 2
3 -> 1

   4 -> 2
3 -> 1

       4 -> 2
3 -> 1

answer: 3 -> 1 -> 4 -> 2


*/

using namespace std;
#include <cstdio>
#include <vector>
#include <queue>

int N;
vector<int> adj[32001];
int indeg[32001];

int main()
{
	int M;
	scanf("%d %d", &N, &M);
	while (M--) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		indeg[b]++;
	}

	priority_queue<int, vector<int>, greater<>> q;
	for (int u = 1; u <= N; u++) {
		if (!indeg[u]) {
			q.push(u);
		}
	}
	while (!q.empty()) {
		int u = q.top(); q.pop();
		printf("%d ", u);
		for (int v : adj[u]) {
			if (!--indeg[v]) {
				q.push(v);
			}
		}
	}
}