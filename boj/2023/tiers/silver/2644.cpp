using namespace std;
#include <cstdio>
#include <vector>

int n;
vector<int> adj[101];

bool visit[101];
int dfs(int u, int b, int d)
{
	if (u == b) {
		return d;
	}

	visit[u] = true;
	for (int v : adj[u]) {
		if (!visit[v]) {
			int t;
			if ((t = dfs(v, b, d + 1)) != -1) {
				return t;
			}
		}
	}
	return -1;
}

int main()
{
	int m, a, b;
	scanf("%d", &n);
	scanf("%d %d", &a, &b);
	scanf("%d", &m);
	while (m--) {
		int x, y;
		scanf("%d %d", &x, &y);
		adj[x].push_back(y), adj[y].push_back(x);
	}
	printf("%d", dfs(a, b, 0));
}