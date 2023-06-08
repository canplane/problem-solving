using namespace std;
#include <cstdio>
#include <algorithm>

int R, C;
char A[20][20];

bool visit[26];
int dy[] = { -1, 0, 0, 1 };
int dx[] = { 0, -1, 1, 0 };
int dfs(int y, int x)
{
	int ret = 1;

	visit[A[y][x] - 'A'] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (!(0 <= ny && ny < R && 0 <= nx && nx < C))
			continue;
		if (!visit[A[ny][nx] - 'A']) {
			ret = max(ret, 1 + dfs(ny, nx));
		}
	}
	visit[A[y][x] - 'A'] = false;

	return ret;
}

int main()
{
	scanf("%d %d", &R, &C);
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			scanf(" %c", &A[y][x]);
		}
	}
	
	printf("%d", dfs(0, 0));
}