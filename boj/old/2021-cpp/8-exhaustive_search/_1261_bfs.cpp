// 어차피 dist[y][x] == INF가 visited[y][x] = false의 역할. 어차피 다시 갱신되어야 하니까 중요치 않다.
// 최단 거리가 갱신되는 것만 큐에 넣기 때문에 found 배열도 필요 없음.

#include <cstdio>
#include <queue>
#include <utility>
using namespace std;

int map[100][100], dist[100][100], N, M;

int dy[4] = { -1, 1, 0, 0 }, dx[4] = { 0, 0, -1, 1 };

int bfs() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			dist[i][j] = 0x7fffffff;

	int ret;
	queue<pair<int, int>> q;
	q.push({ 0, 0 }), dist[0][0] = 0;
	while (!q.empty()) {
		auto [y, x] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;
			if (dist[y][x] + map[ny][nx] < dist[ny][nx])
				q.push({ ny, nx }), dist[ny][nx] = dist[y][x] + map[ny][nx];
		}
	}
	return dist[N - 1][M - 1];
}

int main() {
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%1d", &map[i][j]);
	printf("%d", bfs());
}