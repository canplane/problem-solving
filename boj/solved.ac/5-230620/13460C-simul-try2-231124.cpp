// BOJ 13460 G1 구슬 탈출 2
// 빡센 시뮬레이션 구현 (하루 걸림)
// 시뮬레이션인데 구현이 매우 어려웠습니다. 백트래킹 시에는 두 공의 위치만 관리하면 됩니다. 두 공이 겹치지 않게 하는 것과 더불어, 기울이는 각 방향의 코드 변화와 관련한 복잡성을 잡는 것이 중요한 포인트가 되는 듯 합니다.

using namespace std;
#include <bits/stdc++.h>

int N, M;
int A[10][10];

typedef pair<int, int> P;
P O;

int dy[] = { -1, 0, 0, 1 }, dx[] = { 0, -1, 1, 0 };
P move(int i, P &p)
{
	auto [y, x] = p;
	if (dy[i]) {
		for (; 0 <= y && y < N; y += dy[i])
			if (A[y][x])	break;
	}
	else {
		for (; 0 <= x && x < M; x += dx[i])
			if (A[y][x])	break;
	}

	if (A[y][x] == 1)	y -= dy[i], x -= dx[i];
	return { y, x };
}
pair<P, P> step(int i, P &_R, P &_B)
{
	P R = move(i, _R), B = move(i, _B);
	auto [y, x] = R;
	if (R == B && R != O)	(i < 2 ? (_R < _B ? B : R) : (_R < _B ? R : B)) = { y - dy[i], x - dx[i] };
	return { R, B };
}

int bt(P &R, P &B)
{
	queue<tuple<int, P, P>> q;
	q.push({ 1, R, B });
	while (q.size()) {
		auto [dep, _R, _B] = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			auto [R, B] = step(i, _R, _B);
			if (R == O || B == O) {
				if (B == O)	continue;
				return dep;
			}
			if (dep < 10)	q.push({ dep + 1, R, B });
		}
	}
	return -1;
}

int main()
{
	P R, B;

	scanf("%d %d", &N, &M);
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			char c;
			scanf(" %c", &c);
			if (c == '#')		A[y][x] = 1;
			else if (c == 'O')	A[y][x] = -1, O = { y, x };
			else if (c == 'R')	R = { y, x };
			else if (c == 'B')	B = { y, x };
		}
	}
	printf("%d", bt(R, B));
}