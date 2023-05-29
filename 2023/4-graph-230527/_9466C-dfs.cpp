using namespace std;
#include <cstdio>
#include <cstring>
#include <algorithm>

int adj[100001];

int dep[100001], cycle_nodes;

#define INF (1 << 30)
void dfs(int v, int d)
{
	dep[v] = d;
	
	int w = adj[v];
	if (!dep[w])
		dfs(w, d + 1);
	else if (dep[w] != -1 && dep[w] <= dep[v])
		cycle_nodes += (dep[v] - dep[w] + 1);

	dep[v] = -1;
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
		
		memset(dep, 0, sizeof(dep)), cycle_nodes = 0;
		for (int v = 1; v <= n; v++) {
			if (!dep[v])
				dfs(v, 1);
		}
		printf("%d\n", n - cycle_nodes);
	}
}