using namespace std;
#include <cstdio>
#include <algorithm>

int n;
int t[101];
unsigned int D[101][101];

int main()
{
	int m, r;
	scanf("%d %d %d", &n, &m, &r);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t[i]);
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			D[i][j] = i == j ? 0 : -1;
		}
	}
	while (r--) {
		int a, b, l;
		scanf("%d %d %d", &a, &b, &l);
		D[a][b] = D[b][a] = l;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (D[i][k] != -1 && D[k][j] != -1) {
					D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
				}
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int score = 0;
		for (int j = 1; j <= n; j++) {
			if (D[i][j] <= m) {
				score += t[j];
			}
		}
		ans = max(ans, score);
	}
	printf("%d", ans);
}