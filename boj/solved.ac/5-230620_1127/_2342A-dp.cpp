using namespace std;
#include <cstdio>
#include <algorithm>

#define INF 0x7fffffff

int A[100001], n;
int dp[100001][5][5];

int f[5][5] = {
	{ INF, 2, 2, 2, 2 },
	{ INF, 1, 3, 4, 3 },
	{ INF, 3, 1, 3, 4 },
	{ INF, 4, 3, 1, 3 },
	{ INF, 3, 4, 3, 1 },
};
/* // OR
int f(int i, int j)
{
	int d = abs(i - j);
	if (d == 0)
		return 1;
	if (i == 0 || j == 0)
		return 2;
	if (d == 2)
		return 4;
	return 3;
}*/

int main()
{
	int x;
	while (true) {
		scanf("%d", &x);
		if (x == 0)	break;
		A[++n] = x;
	}

	for (int l = 0; l < 5; l++) {
		for (int r = 0; r < 5; r++) {
			dp[0][l][r] = INF;
		}
	}
	dp[0][0][0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int l = 0; l < 5; l++) {
			for (int r = 0; r < 5; r++) {
				dp[i][l][r] = INF;
			}
		}
		for (int l = 0; l < 5; l++) {
			for (int r = 0; r < 5; r++) {
				if (dp[i - 1][l][r] != INF) {
					dp[i][A[i]][r] = min(dp[i][A[i]][r], dp[i - 1][l][r] + f[l][A[i]]);
					dp[i][l][A[i]] = min(dp[i][l][A[i]], dp[i - 1][l][r] + f[r][A[i]]);
				}
			}
		}
	}

	int ans = INF;
	for (int l = 0; l < 5; l++) {
		for (int r = 0; r < 5; r++) {
			ans = min(ans, dp[n][l][r]);
		}
	}
	printf("%d", ans);
}