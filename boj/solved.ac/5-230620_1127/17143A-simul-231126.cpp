// BOJ 17143 G1 낚시왕
// [주의!] 이동 정보를 현재 맵이 아닌 새로운 맵에 기록하다가 모든 이동이 반영되면 그때 원래의 맵을 덮어써야 함. 두 상어 A, B가 위치가 겹치는 것 같다 하여도 A는 이전 시각, B는 현재 시각일 수 있기 때문에 잡아먹힐 필요가 없는 상어가 잡아먹힐 수 있음.
// 위 문제점 때문에 1%에서 틀리는 상황에서 2시간 동안 빠져나오지 못함. (매 스텝마다 맵 출력해보고 깨달았다.)

#include <bits/stdc++.h>

struct E { int r, c, s, d, z; };

int R, C, M;
E li[10000], *A[101][101], *B[101][101];

void move_y(E *e, int dist)
{
	if (!dist)	return;

	if (e->r == 1)
		e->d = 2;
	else if (e->r == R)
		e->d = 1;

	e->r += e->d == 1 ? -1 : 1;
	move_y(e, dist - 1);
}
void move_x(E *e, int dist)
{
	if (!dist)	return;

	if (e->c == 1)
		e->d = 3;
	else if (e->c == C)
		e->d = 4;

	e->c += e->d == 4 ? -1 : 1;
	move_x(e, dist - 1);
}
void step()
{
	memset(B, 0, sizeof(A));
	for (int i = 0; i < M; i++) {
		E *e = &li[i];
		if (A[e->r][e->c] != e)	continue;

		(e->d <= 2 ? move_y : move_x)(e, e->s);

		E *e1 = B[e->r][e->c];
		if (!e1 || e->z > e1->z)
			B[e->r][e->c] = e;
	}
	memcpy(A, B, sizeof(A));
}

int main()
{
	scanf("%d %d %d", &R, &C, &M);
	for (int i = 0; i < M; i++) {
		E *e = &li[i];
		scanf("%d %d %d %d %d", &e->r, &e->c, &e->s, &e->d, &e->z);
		e->s %= 2 * ((e->d <= 2 ? R : C) - 1);
		A[e->r][e->c] = e;
	}

	int ans = 0;
	for (int t = 1; t <= C; t++) {
		for (int y = 1; y <= R; y++) {
			if (A[y][t]) {
				ans += A[y][t]->z;
				A[y][t] = NULL;
				break;
			}
		}
		step();
	}
	printf("%d", ans);
}