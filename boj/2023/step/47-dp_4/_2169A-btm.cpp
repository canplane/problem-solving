// top-down 메모이제이션보다 시공간적으로 훨씬 빠름

using namespace std;
#include <cstdio>
#include <algorithm>

int N, M;
int A[1000][1000];

int dp[1000][1000], dp1[1000][1000], dp2[1000][1000];

int main()
{
	scanf("%d %d", &N, &M);
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			scanf("%d", &A[y][x]);

	dp[0][0] = A[0][0];
	for (int x = 1; x < M; x++)
		dp[0][x] = A[0][x] + dp[0][x - 1];
	for (int y = 1; y < N; y++) {
		dp1[y][0] = A[y][0] + dp[y - 1][0];
		for (int x = 1; x < M; x++)
			dp1[y][x] = A[y][x] + max(dp1[y][x - 1], dp[y - 1][x]);

		dp2[y][M - 1] = A[y][M - 1] + dp[y - 1][M - 1];
		for (int x = M - 2; x >= 0; x--)
			dp2[y][x] = A[y][x] + max(dp2[y][x + 1], dp[y - 1][x]);
		
		for (int x = 0; x < M; x++)
			dp[y][x] = max(dp1[y][x], dp2[y][x]);
	}
	printf("%d", dp[N - 1][M - 1]);
}