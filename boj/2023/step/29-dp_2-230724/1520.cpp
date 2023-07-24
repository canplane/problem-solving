using namespace std;
#include <bits/stdc++.h>

int M, N;
int A[500][500];

int dp[500][500];
int dy[] = { -1, 0, 0, 1 }, dx[] = { 0, -1, 1, 0 };
int bt(int y, int x)
{
	if (dp[y][x] != -1) {
		return dp[y][x];
	}
	if (y == M - 1 && x == N - 1) {
		return dp[y][x] = 1;
	}
	dp[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (!(0 <= ny && ny < M && 0 <= nx && nx < N)) {
			continue;
		}
		if (A[ny][nx] < A[y][x]) {
			dp[y][x] += bt(ny, nx);
		}
	}
	return dp[y][x];
}

int main()
{
	scanf("%d %d", &M, &N);
	for (int y = 0; y < M; y++) {
		for (int x = 0; x < N; x++) {
			scanf("%d", &A[y][x]);
		}
	}
	
	memset(dp, -1, sizeof(dp));
	printf("%d", bt(0, 0));
}