// 이게 더 구현이 복잡하고 성능도 느림

using namespace std;
#include <cstdio>
#include <algorithm>

#define INF 0x7fffffff

int N;
int W[16][16];

int dp[16][1 << 16];
int f(int v, int visit)
{
	dp[v][visit] = INF;
	for (int w = 1; w < N; w++) {
		if (!(visit & (1 << w))) {
			continue;
		}
		if (W[v][w] == INF) {
			continue;
		}
		if (dp[w][visit & ~(1 << v)] == INF) {
			continue;
		}
		dp[v][visit] = min(dp[v][visit], W[v][w] + dp[w][visit & ~(1 << v)]);
	}
	return dp[v][visit];
}
void combi(int n_i, int r_i, int visit, int r)
{
	if (r_i == r) {
		for (int v = 1; v < N; v++) {
			f(v, visit);
		}
		return;	
	}
	for (int i = n_i; i < N; i++) {
		combi(i + 1, r_i + 1, visit | (1 << i), r);
	}
}

int main()
{
	scanf("%d", &N);
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf("%d", &W[y][x]);
			if (!W[y][x]) {
				W[y][x] = INF;
			}
		}
	}
	for (int v = 1; v < N; v++) {
		dp[v][1 << v] = W[v][0];
	}
	for (int r = 2; r < N; r++) {
		combi(1, 0, 0, r);
	}
	printf("%d", f(0, (1 << N) - 1));
}