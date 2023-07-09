using namespace std;
#include <cstdio>
#include <deque>
#include <tuple>
#include <algorithm>

int M, N, H;
int A[102][102][102];

deque<tuple<int, int, int>> q;
int dz[] = { -1, 0, 0, 0, 0, 1 };
int dy[] = { 0, -1, 0, 0, 1, 0 };
int dx[] = { 0, 0, -1, 1, 0, 0 };
int bfs()
{
	while (!q.empty()) {
		auto [z, y, x] = q.front(); q.pop_front();
		for (int i = 0; i < 6; i++) {
			int nz = z + dz[i], ny = y + dy[i], nx = x + dx[i];
			if (A[nz][ny][nx])
				continue;
			A[nz][ny][nx] = A[z][y][x] + 1;
			q.push_back({ nz, ny, nx });
		}
	}
	int ret = 0;
	for (int z = 1; z <= H; z++) {
		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= M; x++) {
				if (!A[z][y][x])
					return -1;
				ret = max(ret, A[z][y][x]);
			}
		}
	}
	return ret - 1;
}

int main()
{
	scanf("%d %d %d", &M, &N, &H);
	for (int z = 1; z <= H; z++) {
		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= M; x++) {
				scanf("%d", &A[z][y][x]);
				if (A[z][y][x] == 1)
					q.push_back({ z, y, x });
			}
		}
	}
	for (int z = 1; z <= H; z++)
		for (int y = 1; y <= N; y++)
			A[z][y][0] = A[z][y][M + 1] = -1;
	for (int y = 1; y <= N; y++)
		for (int x = 1; x <= M; x++)
			A[0][y][x] = A[H + 1][y][x] = -1;
	for (int x = 1; x <= M; x++)
		for (int z = 1; z <= H; z++)
			A[z][0][x] = A[z][N + 1][x] = -1;
	printf("%d", bfs());
}