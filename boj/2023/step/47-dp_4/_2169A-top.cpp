using namespace std;
#include <cstdio>
#include <algorithm>

#define MIN (1 << 31)

int N, M;
int A[1000][1000];

bool finish[1000][1000][3];
int dp[1000][1000][3];

bool vis[1000][1000];
int dy[] = { 0, 0, 1 }, dx[] = { -1, 1, 0 };
int dfs(int y, int x, int dir)
{
	if (y == N - 1 && x == M - 1)
		return A[y][x];

	int ret = MIN;
	vis[y][x] = true;
	for (int i = 0; i < 3; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if ((0 <= ny && ny < N && 0 <= nx && nx < M) && !vis[ny][nx]) {
			if (!finish[ny][nx][i])
				dp[ny][nx][i] = dfs(ny, nx, i);
			ret = max(ret, dp[ny][nx][i]);
		}
	}
	vis[y][x] = false;
	finish[y][x][dir] = true;

	return ret + ((ret != MIN) ? A[y][x] : 0);
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			scanf("%d", &A[y][x]);
	printf("%d", dp[0][0][2] = dfs(0, 0, 2));
}