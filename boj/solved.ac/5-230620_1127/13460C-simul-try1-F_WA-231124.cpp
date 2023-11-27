// BOJ 13460 G1 구슬 탈출 2
// 빡센 시뮬레이션 구현
// 개빡셈. 2시간 줘도 못 짜겠음. 너무 복잡함.
// 왜 틀렸는지 확인은 하지 않았음. 코드 자체가 복잡해서 별로 좋지 않은 해답이니까. (보드판 모두를 복사하는 코드라 데이터도 많다.)

using namespace std;
#include <bits/stdc++.h>

int N, M;
int Oy, Ox;

pair<bool, bool> move(array<array<char, 11>, 11> &A, int i)
{
	bool R_end = false, B_end = false;

	if (i == 0) {
		for (int x = 1; x <= M; x++) {
			int y0 = 0;
			for (int y = 1; y <= N; y++) {
				if (A[y][x] == 'O') {
					y0 = y;
				}
				else if (A[y][x] == '#') {
					y0 = y + 1;
				}
				else if (A[y][x] == 'R') {
					A[y][x] = '.';
					if (y0 == Oy && x == Ox) {
						R_end = true;
					}
					else {
						A[y0++][x] = 'R';
					}
				}
				else if (A[y][x] == 'B') {
					A[y][x] = '.';
					if (y0 == Oy && x == Ox) {
						B_end = true;
					}
					else {
						A[y0++][x] = 'B';
					}
				}
			}
		}
	}
	else if (i == 1) {
		for (int y = 1; y <= N; y++) {
			int x0 = 0;
			for (int x = 1; x <= M; x++) {
				if (A[y][x] == 'O') {
					x0 = x;
				}
				else if (A[y][x] == '#') {
					x0 = x + 1;
				}
				else if (A[y][x] == 'R') {
					A[y][x] = '.';
					if (y == Oy && x0 == Ox) {
						R_end = true;
					}
					else {
						A[y][x0++] = 'R';
					}
				}
				else if (A[y][x] == 'B') {
					A[y][x] = '.';
					if (y == Oy && x0 == Ox) {
						B_end = true;
					}
					else {
						A[y][x0++] = 'B';
					}
				}
			}
		}
	}
	else if (i == 2) {
		for (int y = 1; y <= N; y++) {
			int x0 = 0;
			for (int x = M; x >= 1; x--) {
				if (A[y][x] == 'O') {
					x0 = x;
				}
				else if (A[y][x] == '#') {
					x0 = x - 1;
				}
				else if (A[y][x] == 'R') {
					A[y][x] = '.';
					if (y == Oy && x0 == Ox) {
						R_end = true;
					}
					else {
						A[y][x0--] = 'R';
					}
				}
				else if (A[y][x] == 'B') {
					A[y][x] = '.';
					if (y == Oy && x0 == Ox) {
						B_end = true;
					}
					else {
						A[y][x0--] = 'B';
					}
				}
			}
		}
	}
	else {
		for (int x = 1; x <= M; x++) {
			int y0 = 0;
			for (int y = N; y >= 1; y--) {
				if (A[y][x] == 'O') {
					y0 = y;
				}
				else if (A[y][x] == '#') {
					y0 = y - 1;
				}
				else if (A[y][x] == 'R') {
					A[y][x] = '.';
					if (y0 == Oy && x == Ox) {
						R_end = true;
					}
					else {
						A[y0--][x] = 'R';
					}
				}
				else if (A[y][x] == 'B') {
					A[y][x] = '.';
					if (y0 == Oy && x == Ox) {
						B_end = true;
					}
					else {
						A[y0--][x] = 'B';
					}
				}
			}
		}
	}

	return { R_end, B_end };
}

int bt(array<array<char, 11>, 11> A)
{
	deque<pair<int, array<array<char, 11>, 11>>> q;
	q.push_back({ 0, A });
	while (!q.empty()) {
		auto [dep, A] = q.front(); q.pop_front();
		for (int i = 0; i < 4; i++) {
			auto nA = A;
			auto [R_end, B_end] = move(nA, i);
			if (R_end || B_end) {
				if (!B_end) {
					return dep + 1;
				}
				continue;
			}

			if (dep < 10) {
				q.push_back({ dep + 1, nA });
			}
		}
	}
	return -1;
}

int main()
{
	array<array<char, 11>, 11> A;

	scanf("%d %d", &N, &M);
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			scanf(" %c", &A[y][x]);
			if (A[y][x] == 'O') {
				Oy = y, Ox = x;
			}
		}
	}

	printf("%d", bt(A));
}