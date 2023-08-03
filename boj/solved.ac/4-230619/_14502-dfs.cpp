using namespace std;
#include <bits/stdc++.h>

#define FOR(x, l, r) for (int x = (l); x < (r); (x)++)

int N, M, A[10][10];

int vis[10][10], dy[] = { -1, 0, 0, 1 }, dx[] = { 0, -1, 1, 0 };
void dfs(int y, int x)
{
	vis[y][x] = 1;
	int ny, nx;
	FOR(i, 0, 4)
		if (A[ny = y + dy[i]][nx = x + dx[i]] && !vis[ny][nx])	dfs(ny, nx);
}
int main()
{
	scanf("%d %d", &N, &M);

	vector<pair<int, int>> B, V;
	FOR(y, 1, N + 1) FOR(x, 1, M + 1)
		scanf("%d", &A[y][x]), --A[y][x] && ((!~A[y][x] ? B : V).push_back({ y, x }), 0);
	
	vector<int> C(3, 1);
	C.resize(B.size());

	int ans = 0;
	do {
		FOR(i, 0, C.size())
			if (C[i])	A[B[i].first][B[i].second] = 0;
		memset(vis, 0, sizeof(vis));
		for (auto [y, x] : V)
			dfs(y, x);
		int cnt = 0;
		FOR(y, 1, N + 1) FOR(x, 1, M + 1)
			cnt += !~A[y][x] && !vis[y][x];
		ans = max(ans, cnt);
		FOR(i, 0, C.size())
			if (C[i])	A[B[i].first][B[i].second] = -1;
	} while (prev_permutation(begin(C), end(C)));
	printf("%d", ans);
}