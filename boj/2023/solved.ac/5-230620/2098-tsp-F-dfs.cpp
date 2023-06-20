// O(n!) : n = 16이라 이거 돌리면 무조건 시간 초과!

using namespace std;
#include <cstdio>
#include <algorithm>

int N;
int W[16][16];

int ans = 0x7fffffff;
bool visit[16];
void dfs(int u, int d, int cost)
{
	visit[u] = true;
	if (d == N) {
		if (W[u][0]) {
			ans = min(ans, cost + W[u][0]);
		}
	}
	else {
		for (int v = 0; v < N; v++) {
			if (!visit[v] && W[u][v]) {
				dfs(v, d + 1, cost + W[u][v]);
			}
		}
	}
	visit[u] = false;
}

int main()
{
	scanf("%d", &N);
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf("%d", &W[y][x]);
		}
	}

	dfs(0, 1, 0);
	printf("%d", ans);
}