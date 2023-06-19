using namespace std;
#include <cstdio>
#include <algorithm>

int A[1001][3];
int N;

int dp[1000][3];

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d %d", &A[i][0], &A[i][1], &A[i][2]);
	}

	for (int i = 1; i <= N; i++) {
		dp[i][0] = A[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = A[i][1] + min(dp[i - 1][2], dp[i - 1][0]);
		dp[i][2] = A[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
	}
	
	int ans = dp[N][0];
	ans = min(ans, dp[N][1]);
	ans = min(ans, dp[N][2]);
	printf("%d", ans);
}