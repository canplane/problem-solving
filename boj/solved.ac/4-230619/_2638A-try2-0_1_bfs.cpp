// BOJ 2638 G3 치즈
// 0-1 BFS

using namespace std;
#include <bits/stdc++.h>

int N, M, A[100][100];

int dy[] = { -1, 0, 0, 1 }, dx[] = { 0, -1, 1, 0 };
int vis[100][100];
deque<tuple<int, int, int>> q;

int main()
{
	scanf("%d %d", &N, &M);
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			scanf("%d", &A[y][x]);

	int ans = 0;
	vis[0][0] = 2, q.push_back({ 0, 0, 0 });
	while (!q.empty()) {
		auto [y, x, t] = q.front(); q.pop_front();
		ans = t;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if ((0 <= ny && ny < N && 0 <= nx && nx < M) && vis[ny][nx] < 2) {
				vis[ny][nx] += !A[ny][nx] + 1;
				if (vis[ny][nx] == 2) {
					if (A[ny][nx])
						q.push_back({ ny, nx, t + 1 });
					else
						q.push_front({ ny, nx, t });
				}
			}
		}
	}
	printf("%d", ans);
}