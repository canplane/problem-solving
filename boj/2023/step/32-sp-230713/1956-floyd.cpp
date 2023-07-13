// O(V^3)

using namespace std;
#include <cstdio>
#include <algorithm>

#define INF ((1L << 30) - 1)
#define MAX_N 400

int N, M;
int D[MAX_N + 1][MAX_N + 1];

int sol()
{
	int ans = INF;

	// init
	for (int i = 1; i <= MAX_N; i++) {
		for (int j = 1; j <= MAX_N; j++) {
			D[i][j] = (i == j) ? 0 : INF;
		}
	}
	scanf("%d %d", &N, &M);
	while (M--) {
		int x, y, cost;
		scanf("%d %d %d", &x, &y, &cost);
		if (x == y) {   //
			ans = min(ans, cost);
		}
		else {
			D[x][y] = cost;
		}
	}

	// floyd
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}

	// get minimum cycle
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != j) {
				ans = min(ans, D[i][j] + D[j][i]);
			}
		}
	}
	return ans == INF ? -1 : ans;
}

int main()
{
	printf("%d", sol());
}