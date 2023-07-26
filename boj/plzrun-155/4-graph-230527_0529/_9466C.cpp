using namespace std;
#include <cstdio>
#include <cstring>

int adj[100001];

int root[100001], dep[100001];

int f(int u)
{
	int v = u, d = 0;
	while (!root[v]) {
		root[v] = u, dep[v] = d;
		int w = adj[v];
		if (root[w] == u)
			return dep[v] - dep[w] + 1;
		v = w, d += 1;
	}
	return 0;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		for (int v = 1; v <= n; v++)
			scanf("%d", &adj[v]);
		
		memset(root, 0, sizeof(root)), memset(dep, 0, sizeof(dep));
		int cycle_nodes = 0;
		for (int v = 1; v <= n; v++) {
			cycle_nodes += f(v);
		}
		printf("%d\n", n - cycle_nodes);
	}
}