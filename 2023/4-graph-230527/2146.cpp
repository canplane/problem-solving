using namespace std;
#include <cstdio>
#include <deque>
#include <tuple>
#include <algorithm>

int A[102][102];
int dist[102][102];
int N;

int dy[] = { -1, 0, 0, 1 };
int dx[] = { 0, -1, 1, 0 };

deque<tuple<int, int>> q;

void color(int y, int x, int c)
{
	A[y][x] = -c, q.push_back({y, x});
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (A[ny][nx] == 1)
			color(ny, nx, c);
	}
}

int bfs()
{
	int ans = 1 << 30;
	while (q.size()) {
		auto [y, x] = q.front(); q.pop_front();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (A[ny][nx] == 0)
				A[ny][nx] = A[y][x], dist[ny][nx] = dist[y][x] + 1, q.push_back({ny, nx});
			else if (A[ny][nx] != -1 && A[ny][nx] != A[y][x])
				ans = min(ans, dist[y][x] + dist[ny][nx]);
		}
	}
	return ans;
}

int main()
{
	scanf("%d", &N);
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			scanf("%1d", &A[y][x]);
		}
	}
	for (int i = 0; i <= N + 1; i++)
		A[0][i] = A[N + 1][i] = A[i][0] = A[i][N + 1] = -1;

	int c = 2;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (A[y][x] == 1)
				color(y, x, c++);
		}
	}
	printf("%d", bfs());
}