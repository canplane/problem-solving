using namespace std;
#include <cstdio>
#include <deque>
#include <utility>

int N, M;
int A[1002][1002], dist[1002][1002];

deque<pair<int, int>> q;
int dy[] = { -1, 0, 0, 1 };
int dx[] = { 0, -1, 1, 0 };
void bfs()
{
	while (!q.empty()) {
		auto [y, x] = q.front(); q.pop_front();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (!A[ny][nx] || dist[ny][nx] >= 0) {
				continue;
			}
			dist[ny][nx] = dist[y][x] + 1;
			q.push_back({ ny, nx });
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			scanf("%d", &A[y][x]);
			if (A[y][x] == 2) {
				A[y][x] = 0;
				q.push_back({ y, x });
			}
			else if (A[y][x] == 1) {
				dist[y][x] = -1;
			}
		}
	}
	bfs();
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			printf("%d ", dist[y][x]);
		}
		printf("\n");
	}
}