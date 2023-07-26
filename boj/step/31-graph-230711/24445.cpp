#include <cstdio>
#include <set>
#include <queue>

int N, R;
std::set<int> adj[100001];

std::queue<int> q;
int bfn[100001], max_bfn;
int main()
{
	int M, u, v;
	scanf("%d %d %d", &N, &M, &R);
	while (M--) {
		scanf("%d %d", &u, &v);
		adj[u].insert(-v), adj[v].insert(-u);
	}

	bfn[R] = ++max_bfn, q.push(R);
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int v : adj[u]) {
			if (!bfn[-v]) {
				bfn[-v] = ++max_bfn, q.push(-v);
			}
		}
	}
	
	for (int i = 1; i <= N; i++)
		printf("%d\n", bfn[i]);
}