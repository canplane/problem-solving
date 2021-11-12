/* dp + dfs */

#include <cstdio>

char map[100][100], word[81];
int N, M, K;

int memo[100][100][80];  // y, x, idx

int dy[4] = { -1, 1, 0, 0 }, dx[4] = { 0, 0, -1, 1 };

int dfs(int y, int x, int idx) {    
	if (map[y][x] != word[idx])
		return 0;
	if (!word[idx + 1])
		return 1;

	int ret = 0;
	for (int i = 0; i < 4; i++) {
		for (int k = 1; k <= K; k++) {
			int ny = y + k * dy[i], nx = x + k * dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;
			if (!memo[ny][nx][idx + 1])
				memo[ny][nx][idx + 1] = dfs(ny, nx, idx + 1) + 1;
			ret += memo[ny][nx][idx + 1] - 1;
 		}
	}
	return ret;
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			scanf(" %c", &map[y][x]);
	scanf("%s", word);

	int ans = 0;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			if (map[y][x] == word[0])
				ans += dfs(y, x, 0);
	printf("%d", ans);
}