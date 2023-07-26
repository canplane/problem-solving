using namespace std;
#include <cstdio>
#include <deque>
#include <utility>

int A[102][102];
int N, M;

int dy[] = { -1, 0, 0, 1 };
int dx[] = { 0, -1, 1, 0 };
int bfs()
{
	int ret;
	deque<pair<int, int>> q;
	A[1][1] = -1, q.push_back({1, 1});
	while (q.size()) {
		auto [y, x] = q.front(); q.pop_front();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (!(1 <= ny && ny <= N && 1 <= nx && nx <= M))
				continue;
			if (A[ny][nx] == 1)
				A[ny][nx] = A[y][x] - 1, q.push_back({ny, nx});
		}
	}
	return -A[N][M];
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			scanf("%1d", &A[y][x]);
		}
	}
	printf("%d", bfs());
}