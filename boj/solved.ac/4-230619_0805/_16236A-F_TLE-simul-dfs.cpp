// BOJ 16236 G3 아기 상어
// DFS로 하나씩 하다 보면 시간 터짐

using namespace std;
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

#define INF ((1L << 30) - 1)

int N;
int A[20][20];

vector<pair<int, int>> fish;
int y0, x0, sz = 2, expe;

bool vis[20][20];
int dy[] = { -1, 0, 0, 1 }, dx[] = { 0, -1, 1, 0 };
int dfs(int y, int x, int y1, int x1)
{
	if (y == y1 && x == x1) {
		return 0;
	}

	int ret = INF;
	vis[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if ((0 <= ny && ny < N && 0 <= nx && nx < N) && A[ny][nx] <= sz && !vis[ny][nx]) {
			ret = min(ret, 1 + dfs(ny, nx, y1, x1));
		}
	}
	vis[y][x] = false;
	return ret;
}

int main()
{
	scanf("%d", &N);
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf("%d", &A[y][x]);
			if (A[y][x]) {
				if (A[y][x] == 9) {
					A[y0 = y][x0 = x] = 0;
				}
				else {
					fish.push_back({ y, x });
				}
			}
		}
	}
	
	int ans = 0;
	while (true) {
		int d1 = INF, y1, x1;
		for (auto [y, x] : fish) {
			if (A[y][x] && A[y][x] < sz) {
				int d = dfs(y0, x0, y, x);
				if (d < d1) {
					d1 = d, y1 = y, x1 = x;
				}
			}
		}
		if (d1 == INF) {
			break;
		}
		ans += d1, A[y0 = y1][x0 = x1] = 0;
		++expe;
		if (expe == sz) {
			++sz, expe = 0;
		}
	}
	printf("%d", ans);
}