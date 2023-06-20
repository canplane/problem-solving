using namespace std;
#include <cstdio>
#include <algorithm>

int N;
int W[16][16];

int dp[16][65536];

#define INF 0x7fffffff
int _comb[16], comb[16];
void combi(int r, int n_i, int r_i)
{
	if (r_i == r) {
		int A = 0;
		for (int u = 0; u < r; u++) {
			A |= (1 << comb[u]);
		}
		for (int i = 0; i < r; i++) {
			int u = comb[i];
			A &= ~(1 << u);
			dp[u][A] = INF;
			for (int j = 0; j < r; j++) {
				int v = comb[j];
				if (u != v && (W[u][v] != INF && dp[v][A & ~(1 << v)] != INF)) {
					dp[u][A] = min(dp[u][A], W[u][v] + dp[v][A & ~(1 << v)]);
				}
			}
			A |= (1 << u);
		}
		return;
	}
	for (int i = n_i; i < N; i++) {
		comb[r_i] = _comb[i], combi(r, i + 1, r_i + 1);
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
	for (int i = 0; i < N; i++) {
		_comb[i] = i;
	}

	for (int u = 0; u < N; u++) {
		dp[u][0] = W[u][0];
	}
	for (int r = 2; r <= N - 1; r++) {
		combi(r, 0, 0);
	}
	printf("%d", dp[0][65535 & ~1]);
}