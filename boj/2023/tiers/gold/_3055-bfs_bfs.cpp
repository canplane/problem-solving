/* bfs + bfs
	틀린 이유: 지점별 물이 도달하는 시점 저장을 할 때, 도달하지 못하는 지점에 대해서 INF가 아니라 0으로 세팅해서 고슴도치도 이동하지 못하게 함
*/

using namespace std;
#include <cstdio>
#include <deque>
#include <tuple>
#include <cstring>

#define INF 0x7fffffff

int R, C;
char A[51][51];

int water[51][51];

int dy[] = { -1, 0, 0, 1 };
int dx[] = { 0, -1, 1, 0 };
void bfs_water()
{
	deque<tuple<int, int>> q;
	for (int y = 1; y <= R; y++) {
		for (int x = 1; x <= C; x++) {
			if (A[y][x] == '*')
				water[y][x] = 1, q.push_back({ y, x });
			else
				water[y][x] = INF;
		}
	}
	while (!q.empty()) {
		auto [y, x] = q.front(); q.pop_front();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (!(1 <= ny && ny <= R && 1 <= nx && nx <= C))
				continue;
			if (A[ny][nx] == '.' && water[ny][nx] == INF)
				water[ny][nx] = water[y][x] + 1, q.push_back({ ny, nx });
		}
	}
}
bool visit[51][51];
int bfs_hedge(int y0, int x0)
{
	deque<tuple<int, int, int>> q;
	visit[y0][x0] = true, q.push_back({ y0, x0, 1 });
	while (!q.empty()) {
		auto [y, x, d] = q.front(); q.pop_front();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (!(1 <= ny && ny <= R && 1 <= nx && nx <= C))
				continue;
			if (A[ny][nx] == 'D')
				return d + 1;
			if (A[ny][nx] == '.' && d + 1 < water[ny][nx] && !visit[ny][nx])
				visit[ny][nx] = true, q.push_back({ ny, nx, d + 1 }); 
		}
	}
	return -1;
}

int main()
{
	int y0, x0;
	scanf("%d %d", &R, &C);
	for (int y = 1; y <= R; y++) {
		for (int x = 1; x <= C; x++) {
			scanf(" %c", &A[y][x]);
			if (A[y][x] == 'S') {
				A[y][x] = '.';
				y0 = y, x0 = x;
			}
		}
	}

	bfs_water();
	int ans = bfs_hedge(y0, x0);
	if (ans == -1)
		printf("KAKTUS");
	else
		printf("%d", ans - 1);
}