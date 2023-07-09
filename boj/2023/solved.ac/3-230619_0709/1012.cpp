#include <cstdio>
#include <cstring>

int A[52][52], N, M;

void dfs(int y, int x)
{
	if (!A[y][x])	return;
	A[y][x] = 0, dfs(y - 1, x), dfs(y, x - 1), dfs(y, x + 1), dfs(y + 1, x);
}
int main()
{
	int T, K, y, x, ans;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &M, &N, &K);
		memset(A, 0, sizeof(A));
		while (K--)
			scanf("%d %d", &x, &y), A[y + 1][x + 1] = true;
		ans = 0;
		for (y = 1; y <= N; y++)
			for (x = 1; x <= M; x++)
				if (A[y][x])
					ans++, dfs(y, x);
		printf("%d\n", ans);
	}
}