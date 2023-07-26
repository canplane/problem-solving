#include <cstdio>
#include <set>
#include <queue>

int N, R;
std::set<int> adj[100001];

std::queue<int> q;
int bfn[100001], max_bfn;
void bfs(int u)
{
	bfn[u] = ++max_bfn, q.push(u);
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int v : adj[u]) {
			if (!bfn[v]) {
				bfn[v] = ++max_bfn, q.push(v);
			}
		}
	}
}

int main()
{
	int M, u, v;
	scanf("%d %d %d", &N, &M, &R);
	while (M--) {
		scanf("%d %d", &u, &v);
		adj[u].insert(v), adj[v].insert(u);
	}
	bfs(R);
	for (int i = 1; i <= N; i++)
		printf("%d\n", bfn[i]);
}