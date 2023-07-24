// 아이템 줍기: https://school.programmers.co.kr/learn/courses/30/lessons/87694
// [26 mins]

using namespace std;
#include <cstdio>
#include <algorithm>

#define INF ((1L << 30) - 1)

int y1, x1;
bool A[102][102], B[102][102];

bool vis[102][102];
int dy[] = { -1, 0, 0, 1 }, dx[] = { 0, -1, 1, 0 };
int dfs(int y, int x)
{
	if (y == y1 && x == x1) {
		return 0;
	}

	int ret = INF;
	vis[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (B[ny][nx] && !vis[ny][nx]) {
			ret = min(ret, 1 + dfs(ny, nx));
		}
	}
	return ret;
}

int solution(vector<vector<int>> rects, int x0, int y0, int _x1, int _y1) {
	y1 = _y1, x1 = _x1;
	y0 *= 2, x0 *= 2, y1 *= 2, x1 *= 2;

	for (auto rect : rects) {
		int xm = rect[0], ym = rect[1], xM = rect[2], yM = rect[3];
		for (int y = 2 * ym; y <= 2 * yM; y++) {
			for (int x = 2 * xm; x <= 2 * xM; x++) {
				A[y][x] = true;
			}
		}
	}

	// make border lines
	for (int y = 1; y <= 100; y++) {
		for (int x = 1; x <= 100; x++) {
			B[y][x] = A[y][x] && !(A[y - 1][x - 1] && A[y - 1][x] && A[y - 1][x + 1] && A[y][x - 1] && A[y][x + 1] && A[y + 1][x - 1] && A[y + 1][x] && A[y + 1][x + 1]);
		}
	}

	return dfs(y0, x0) / 2;
}