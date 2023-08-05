// BOJ 2638 G3 치즈
// GG: 반례 도움: https://www.acmicpc.net/board/view/32174
// DFS + BFS: 바깥 공기 찾기 + 치즈 녹이기

using namespace std;
#include <bits/stdc++.h>

int N, M, A[100][100];

int dy[] = { -1, 0, 0, 1 }, dx[] = { 0, -1, 1, 0 };
bool check(int y, int x)
{
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		cnt += A[ny][nx] == -1;
	}
	return cnt >= 2;
}

deque<tuple<int, int, int>> q;
bool vis[100][100];
void dfs(int y, int x, int t)
{
	A[y][x] = -1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (0 <= ny && ny < N && 0 <= nx && nx < M) {
			if (!A[ny][nx])
				dfs(ny, nx, t);
			else if (A[ny][nx] == 1 && !vis[ny][nx] && check(ny, nx))
				vis[ny][nx] = true, q.push_back({ ny, nx, t + 1 });	
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			scanf("%d", &A[y][x]);

	int ans = 0;
	dfs(0, 0, 0);
	while (!q.empty()) {
		auto [y, x, t] = q.front(); q.pop_front();
		ans = t;
		dfs(y, x, t);
	}
	printf("%d", ans);
}