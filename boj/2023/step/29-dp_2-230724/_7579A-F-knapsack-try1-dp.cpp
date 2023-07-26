// 1st trial: Failed
// memory를 기준으로 하면 너무 공간이 많음 -> cost로 변경

using namespace std;
#include <cstdio>
#include <algorithm>

#define INF 0x7fffffff

int N, M;
int m[101], c[101];
int dp[101][10000001];

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
		scanf("%d", &m[i]);
	for (int j = 1; j <= N; j++)
		scanf("%d", &c[j]);

	dp[0][0] = 0;
	for (int j = 1; j <= M; j++)
		dp[0][j] = INF;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = dp[i - 1][j];
			if (m[i] < j) {
				if (dp[i - 1][j - m[i]] != INF)
					dp[i][j] = min(dp[i][j], dp[i - 1][j - m[i]] + c[i]);
			}
			else
				dp[i][j] = min(dp[i][j], c[i]);
		}
	}
	printf("%d", dp[N][M]);
}