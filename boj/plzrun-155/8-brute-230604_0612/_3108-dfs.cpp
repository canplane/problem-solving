/*
	오래 걸린 이유: 좌표 두 배 해야 하는 것 잊음 (안 하면 서로 다른 도형끼리 인접해짐)
*/

#include <cstdio>

#define SZ 2001
bool A[SZ][SZ];

int dy[] = { -1, 0, 0, 1 };
int dx[] = { 0, -1, 1, 0 };
void dfs(int y, int x)
{
	A[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (!(0 <= ny && ny < SZ && 0 <= nx && nx < SZ))
			continue;
		if (A[ny][nx])
			dfs(ny, nx);
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		x1 *= 2, y1 *= 2, x2 *= 2, y2 *= 2;
		x1 += 1000, y1 += 1000, x2 += 1000, y2 += 1000;
		for (int y = y1; y <= y2; y++)
			A[y][x1] = A[y][x2] = 1;
		for (int x = x1; x <= x2; x++)
			A[y1][x] = A[y2][x] = 1;
	}

	int ans = -A[1000][1000];
	for (int y = 0; y < SZ; y++) {
		for (int x = 0; x < SZ; x++) {
			if (A[y][x])
				++ans, dfs(y, x);
		}
	}
	printf("%d", ans);
}