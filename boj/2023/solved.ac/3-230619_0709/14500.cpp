#include <bits/stdc++.h>

int N, M, A[502][502];

int dy[] = { -1, 0, 0, 1 }, dx[] = { 0, -1, 1, 0 };
int dfs(int y, int x, int d)
{
	if (d == 4)
		return 0;

	int ret = 0, a = A[y][x], i, ny, nx;
	A[y][x] = 0;
	for (i = 0; i < 4; i++)
		if (A[ny = y + dy[i]][nx = x + dx[i]])
			ret = std::max(ret, dfs(ny, nx, d + 1));
	A[y][x] = a;
	return a + ret;
}
int T(int y, int x)
{
	int sum = A[y][x], ret = 0, i;
	for (i = 0; i < 4; i++)
		sum += A[y + dy[i]][x + dx[i]];
	for (i = 0; i < 4; i++)
		ret = std::max(ret, sum - A[y + dy[i]][x + dx[i]]);
	return ret;
}
int main()
{
	int ans = 0, y, x;
	scanf("%d %d", &N, &M);
	for (y = 1; y <= N; y++)
		for (x = 1; x <= M; x++)
			scanf("%d", &A[y][x]);

	for (y = 1; y <= N; y++)
		for (x = 1; x <= M; x++)
			ans = std::max(std::max(ans, dfs(y, x, 0)), T(y, x));
	printf("%d", ans);
}