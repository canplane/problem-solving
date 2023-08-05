// BOJ 17144 G4 미세먼지 안녕!

using namespace std;
#include <bits/stdc++.h>

int R, C, A[50][50], dA[50][50];
int top = -1, btm = -1;

int dy[] = { -1, 0, 0, 1 }, dx[] = { 0, -1, 1, 0 };
void simul()
{
	memset(dA, 0, sizeof(dA));
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (A[y][x] > 0) {
				for (int i = 0; i < 4; i++) {
					int ny = y + dy[i], nx = x + dx[i];
					if (0 <= ny && ny < R && 0 <= nx && nx < C) {
						if (nx == 0 && (ny == top || ny == btm)) {
							continue;
						}
						dA[y][x] -= A[y][x] / 5;
						dA[ny][nx] += A[y][x] / 5;
					}
				}
			}
		}
	}
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			A[y][x] += dA[y][x];
		}
	}

	for (int y = top - 1; y - 1 >= 0; y--) {
		A[y][0] = A[y - 1][0];
	}
	for (int x = 0; x + 1 < C; x++) {
		A[0][x] = A[0][x + 1];
	}
	for (int y = 0; y + 1 <= top; y++) {
		A[y][C - 1] = A[y + 1][C - 1];
	}
	for (int x = C - 1; x - 1 >= 0; x--) {
		A[top][x] = A[top][x - 1];
	}

	for (int y = btm + 1; y + 1 < R; y++) {
		A[y][0] = A[y + 1][0];
	}
	for (int x = 0; x + 1 < C; x++) {
		A[R - 1][x] = A[R - 1][x + 1];
	}
	for (int y = R - 1; y - 1 >= btm; y--) {
		A[y][C - 1] = A[y - 1][C - 1];
	}
	for (int x = C - 1; x - 1 >= 0; x--) {
		A[btm][x] = A[btm][x - 1];
	}
}

int main()
{
	int T;
	scanf("%d %d %d", &R, &C, &T);
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			scanf("%d", &A[y][x]);
			if (A[y][x] == -1) {
				A[y][x] = 0;
				if (top == -1) {
					top = y;
				}
				else {
					btm = y;
				}
			}
		}
	}

	while (T--) {
		simul();	
	}

	int ans = 0;
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (A[y][x] > 0) {
				ans += A[y][x];
			}
		}
	}
	printf("%d", ans);
}