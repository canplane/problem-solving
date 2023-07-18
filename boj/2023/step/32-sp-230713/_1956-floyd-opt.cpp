// O(V^3)
// 최적화해도 별 차이가 업네.. 데이터 수가 적어서 그런 듯.
// 플로이드는 작은 거부터 뽑는 거 아니라서 사이클 감지했다고 바로 리턴하면 안 됨.

using namespace std;
#include <cstdio>
#include <algorithm>

#define INF ((1L << 30) - 1)
#define MAX_N 400

int N, M;
int D[MAX_N + 1][MAX_N + 1];

int sol()
{
	// init
	for (int i = 1; i <= MAX_N; i++) {
		for (int j = 1; j <= MAX_N; j++) {
			D[i][j] = INF;
		}
	}
	scanf("%d %d", &N, &M);
	while (M--) {
		int x, y, cost;
		scanf("%d %d %d", &x, &y, &cost);
		D[x][y] = cost;
	}

	// floyd
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			if (D[i][k] == INF) {
				continue;
			}
			for (int j = 1; j <= N; j++) {
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}

	// get minimum cycle
	int ans = INF;
	for (int i = 1; i <= N; i++) {
		ans = min(ans, D[i][i]);
	}
	return ans == INF ? -1 : ans;
}

int main()
{
	printf("%d", sol());
}