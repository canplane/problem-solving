using namespace std;
#include <cstdio>
#include <algorithm>

int N;
int cost[10][10];
bool visit[10];

#define INF -1L
unsigned long dfs(int v, int dep)
{
	if (dep == N) {
		return cost[v][0] ? cost[v][0] : INF;
	}

	unsigned long ret = INF;
	visit[v] = true;
	for (int w = 0; w < N; w++) {
		if (!visit[w] && cost[v][w]) {
			unsigned long tmp = dfs(w, dep + 1);
			if (tmp != INF)
				tmp += cost[v][w];
			ret = min(ret, tmp);
		}
	}
	visit[v] = false;
	return ret;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &cost[i][j]);
		}
	}

	printf("%lu", dfs(0, 1));
}