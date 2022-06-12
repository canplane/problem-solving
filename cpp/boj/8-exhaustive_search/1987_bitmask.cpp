/* visited 칸이 26개이므로 비트 마스킹으로 풀어도 된다. */

#include <cstdio>

int R, C, ans;
char map[20][20];

int dy[4] = { -1, 1, 0, 0 }, dx[4] = { 0, 0, -1, 1 };

void dfs(int y, int x, int dep, int visit) {
	if (dep > ans)
		ans = dep;

	visit |= 1 << (map[y][x] - 'A');
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (ny < 0 || ny >= R || nx < 0 || nx >= C)
			continue;
		if (visit & (1 << (map[ny][nx] - 'A')))
			continue;
		dfs(ny, nx, dep + 1, visit);
	}
}

int main() {
	scanf("%d %d", &R, &C);
	for (int y = 0; y < R; y++)
		for (int x = 0; x < C; x++)
			scanf(" %c", &map[y][x]);
	dfs(0, 0, 1, 0);
	printf("%d", ans);
}