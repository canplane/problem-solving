// nqueen : backtracking

#include <cstdio>

int N;
bool visit_x[15], visit_xy[29], visit_yx[29];

int dfs(int y)
{
	if (y == N + 1)
		return 1;
	
	int cnt = 0;
	for (int x = 1; x <= N; x++) {
		if (visit_x[x] || visit_xy[x + y] || visit_yx[x - y + N])
			continue;
		visit_x[x] = visit_xy[x + y] = visit_yx[x - y + N] = true;
		cnt += dfs(y + 1);
		visit_x[x] = visit_xy[x + y] = visit_yx[x - y + N] = false;
	}
	return cnt;
}

int main()
{
	scanf("%d", &N);
	printf("%d", dfs(1));
}