using namespace std;
#include <cstdio>
#include <deque>
#include <tuple>

int N, M;
int A[100][100];

int d[100][100];

int dy[] = { -1, 0, 0, 1 };
int dx[] = { 0, -1, 1, 0 };
int bfs_01(int vy, int vx, int uy, int ux)
{
	deque<tuple<int, int>> q;
	d[vy][vx] = 1, q.push_back({ vy, vx });
	while (!q.empty()) {
		auto [y, x] = q.front(); q.pop_front();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (!(0 <= ny && ny < N && 0 <= nx && nx < M))
				continue;
			if (!d[ny][nx]) {
				d[ny][nx] = d[y][x] + A[ny][nx];
				if (A[ny][nx])
					q.push_back({ ny, nx });
				else
					q.push_front({ ny, nx });
			}
		}
	}
	return d[uy][ux] - 1;
}

int main()
{
	scanf("%d %d", &M, &N);
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			scanf("%1d", &A[y][x]);
		}
	}
	printf("%d", bfs_01(0, 0, N - 1, M - 1));
}