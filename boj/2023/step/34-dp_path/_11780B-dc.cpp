// 플로이드 경로는 분할 정복으로 가능!
// 플로이드에서 거리 갱신 시 매개한 중간 노드를 기록해놓고 분할 정복하는 방법

using namespace std;
#include <cstdio>
#include <algorithm>
#include <vector>

#define INF ((1L << 30) - 1)

int n;
int D[101][101], mi[101][101];	// 중간에 거치는 점

template <class T>
void path(T& p, int i, int j)
{
	int k = mi[i][j];
	if (k) {
		path(p, i, k), path(p, k, j);
	}
	else {
		p.push_back(i);
	}
}

int main()
{
	int m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				D[i][j] = INF;
			}
		}
	}
	while (m--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		D[a][b] = min(D[a][b], c);
	}

	// floyd
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (D[i][k] + D[k][j] < D[i][j]) {
					D[i][j] = D[i][k] + D[k][j];
					mi[i][j] = k;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", D[i][j] == INF ? 0 : D[i][j]);
		}
		printf("\n");
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			vector<int> p;
			if (!(i == j || (D[i][j] == INF))) {
				path(p, i, j), p.push_back(j);
			}
			printf("%ld ", size(p));
			for (int k : p) {
				printf("%d ", k);
			}
			printf("\n");
		}
	}
}