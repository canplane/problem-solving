using namespace std;
#include <cstdio>
#include <algorithm>

#define INF 0x7ffffff

int D[101][101];
int n, m;

int main()
{
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			D[i][j] = i == j ? 0 : INF;
		}
	}

	scanf("%d %d", &n, &m);
	while (m--) {
		int i, j, w;
		scanf("%d %d %d", &i, &j, &w);
		D[i][j] = min(D[i][j], w);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (D[i][k] == INF || D[k][j] == INF)
					continue;
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", D[i][j] == INF ? 0 : D[i][j]);
		}
		printf("\n");
	}
}