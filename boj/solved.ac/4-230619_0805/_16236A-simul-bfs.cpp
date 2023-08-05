// BOJ 16236 G3 아기 상어
// BFS 시뮬레이션

using namespace std;
#include <bits/stdc++.h>

int N, A[20][20];
int Y0, X0, sz = 2, expe;
int ans;

bool vis[20][20];
int dy[] = { -1, 0, 0, 1 }, dx[] = { 0, -1, 1, 0 };
bool bfs()
{
	memset(vis, 0, sizeof(vis));

	uint D = -1, Y, X;
	queue<tuple<int, int, int>> q;
	vis[Y0][X0] = 1, q.push({ Y0, X0, 0 });
	while (!q.empty()) {
		auto [y, x, d] = q.front(); q.pop();
		if (d > D)
			break;
		if (A[y][x] && A[y][x] < sz)
			if (D == -1 || (y < Y || (y == Y && x < X)))
				D = d, Y = y, X = x;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if ((0 <= ny && ny < N && 0 <= nx && nx < N) && A[ny][nx] <= sz && !vis[ny][nx])
				vis[ny][nx] = 1, q.push({ ny, nx, d + 1 });
		}
	}
	if (D < -1) {
		ans += D, A[Y0 = Y][X0 = X] = 0;
		if (++expe == sz)
			++sz, expe = 0;
	}
	return D < -1;
}
int main()
{
	scanf("%d", &N);
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++) {
			scanf("%d", &A[y][x]);
			if (A[y][x] == 9)
				A[Y0 = y][X0 = x] = 0;
		}

	while (bfs());
	printf("%d", ans);
}