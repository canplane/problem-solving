using namespace std;
#include <cstdio>

int N, M;
char A[600][600];
bool visit[600][600];

int dy[] = { -1, 0, 0, 1 }, dx[] = { 0, -1, 1, 0 };
int dfs(int y, int x)
{
	visit[y][x] = true;

	int ret = (A[y][x] == 'P');
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (!(0 <= ny && ny < N && 0 <= nx && nx < M)) {
			continue;
		}
		if (A[ny][nx] != 'X' && !visit[ny][nx]) {
			ret += dfs(ny, nx);
		}
	}
	return ret;
}

int main()
{
	int y0, x0;
	scanf("%d %d", &N, &M);
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			scanf(" %c", &A[y][x]);
			if (A[y][x] == 'I') {
				y0 = y, x0 = x;
			}
		}
	}
	int ans = dfs(y0, x0);
	if (ans) {
		printf("%d", ans);
	}
	else {
		printf("TT");
	}
}