// 틀린 이유: root가 삭제될 때, 삭제된 노드가 부모의 유일한 자식일 때 고려 안 함

using namespace std;
#include <cstdio>
#include <vector>

int N;
int parent[50];
int x;

int r;
vector<int> adj[50];

int dfs(int u)
{
	int deg = 0, leaves = 0;
	for (int v : adj[u]) {
		if (v == x)
			continue;
		deg++, leaves += dfs(v);
	}
	if (deg == 0)
		leaves = 1;
	return leaves;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &parent[i]);
	scanf("%d", &x);

	for (int v = 0; v < N; v++) {
		int u = parent[v];
		if (u == -1) {
			r = v;
			continue;
		}
		adj[u].push_back(v);
	}
	printf("%d", r == x ? 0 : dfs(r));
}