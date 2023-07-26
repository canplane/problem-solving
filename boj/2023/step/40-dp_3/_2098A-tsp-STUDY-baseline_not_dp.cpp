// 먼저 brute로 짜고 나중에 dp 얹기! (이 코드 바로 쓰면 n^n 코드라 시간 초과난다.)
// dfs 실행 횟수: T(n) = 1 + (n-1)T(n-1), T(1) = 1 -> T(n) = (n-1)P0 + (n-1)P1 + ... + (n-1)P(n-1) = e gamma(n, 1) ~ e (n-1)!

using namespace std;
#include <bits/stdc++.h>
#define INF ((1L << 30) - 1)

int N;
int adj[16][16];

int cnt;
bool vis[16];
int dfs(int v, int d)
{
	cnt++;
	if (d == N - 1) {
		return adj[v][0] ? adj[v][0] : INF;
	}

	int ret = INF;
	vis[v] = true;
	for (int w = 0; w < N; w++) {
		if (!vis[w] && adj[v][w]) {
			ret = min(ret, adj[v][w] + dfs(w, d + 1));
		}
	}
	vis[v] = false;
	return ret;
}

int main()
{
	scanf("%d", &N);
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf("%d", &adj[y][x]);
		}
	}
	printf("%d ", dfs(0, 0));
	printf("%d", cnt);
}