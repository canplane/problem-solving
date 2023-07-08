#include <bits/stdc++.h>

char N, A[102][102];
int vis[102][102], dy[] = { -1, 0, 0, 1 }, dx[] = { 0, -1, 1, 0 };
void dfs(int y, int x)
{
	int i = 4, ny, nx;
	vis[y][x] = 1;
	while (i--)
		(!vis[ny = y + dy[i]][nx = x + dx[i]] && A[ny][nx] == A[y][x]) && (dfs(ny, nx), 0);
	A[y][x] == 'G' && (A[y][x] = 'R');
}
void f()
{
	int ans = 0, y, x;
	memset(vis, 0, sizeof(vis));
	for (y = 1; y <= N; y++)
		for (x = 1; x <= N; x++)
			!vis[y][x] && (dfs(y, x), ans++);
	printf("%d ", ans);
}
int main()
{
	while (~scanf("%s", A[N++] + 1));
	N -= 2, f(), f();
}