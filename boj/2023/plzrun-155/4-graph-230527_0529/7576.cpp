using namespace std;
#include <cstdio>
#include <deque>
#include <utility>

int A[1002][1002];
int N, M;

int dy[] = { -1, 0, 0, 1 };
int dx[] = { 0, -1, 1, 0 };
int bfs()
{
	int ret;
	deque<pair<int, int>> q;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			if (A[y][x] == 1)
				ret = A[y][x] = 1, q.push_back({y, x});
		}
	}
	while (q.size()) {
		auto [y, x] = q.front(); q.pop_front();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (!(1 <= ny && ny <= N && 1 <= nx && nx <= M))
				continue;
			if (A[ny][nx] == 0)
				ret = A[ny][nx] = A[y][x] + 1, q.push_back({ny, nx});
		}
	}
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			if (A[y][x] == 0)
				return -1;
		}
	}
	return ret - 1;
}

int main()
{
	scanf("%d %d", &M, &N);
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			scanf("%d", &A[y][x]);
		}
	}
	printf("%d", bfs());
}