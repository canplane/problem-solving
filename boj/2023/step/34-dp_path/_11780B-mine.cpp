// D[i][k] + edge[k][j] = D[i][j]인 k를 찾아서 역추적하는 방법

using namespace std;
#include <cstdio>
#include <algorithm>
#include <deque>

#define INF ((1L << 30) - 1)

int n;
int D[101][101], A[101][101];
int pre[101][101];

void path(int i, int j)
{
	if (i == j || D[i][j] == INF) {
		printf("0\n");
		return;
	}
	
	deque<int> s;
	s.push_front(j);
	while (j != i) {
		s.push_front(j = pre[i][j]);
	}
	printf("%d ", s.size());
	for (int k : s) {
		printf("%d ", k);
	}
	printf("\n");
}

int main()
{
	int m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				A[i][j] = INF;
			}
		}
	}
	while (m--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		A[a][b] = min(A[a][b], c);
	}

	// floyd
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			D[i][j] = A[i][j];
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}

	// prev
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (k != j && D[i][j] == D[i][k] + A[k][j]) {
					pre[i][j] = k;
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
			path(i, j);
		}
	}
}