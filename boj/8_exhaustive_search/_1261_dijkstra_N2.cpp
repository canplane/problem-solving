#include <cstdio>
#include <algorithm>
#define MAX 0x7fffffff

int map[100][100], N, M;

int dy[4] = { -1, 1, 0, 0 }, dx[4] = { 0, 0, -1, 1 };

int dist[100][100];
bool found[100][100];

int dijkstra() {
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			dist[i][j] = MAX, found[i][j] = false;
	int y = 0, x = 0;
	dist[0][0] = 0;

	for (int _i = 0; _i < 100 * 100 - 1; _i++) {
		found[y][x] = true;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;
			if (found[ny][nx])
				continue;
			dist[ny][nx] = std::min(dist[ny][nx], dist[y][x] + map[ny][nx]);
		}

		y = -1;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				if (found[i][j] || dist[i][j] == MAX)
					continue;
				if (y == -1 || dist[i][j] < dist[y][x])
					y = i, x = j;
			}
		}
		if (y == -1)
			break;
	}
	return dist[N - 1][M - 1];
}

int main() {
	scanf("%d %d", &M, &N);
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			scanf("%1d", &map[y][x]);

	printf("%d", dijkstra());
}