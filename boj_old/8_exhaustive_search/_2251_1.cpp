/* 옮기는 양에만 집중해라! */

#include <cstdio>
#include <algorithm>
using namespace std;

bool visit[201][201];
int A, B, C;

void dfs(int a, int b, int c) {
	if (visit[a][c])
		return;
	visit[a][c] = true;

	int move;
	if (a > 0) {
		if (B - b > 0)
			move = min(a, B - b), dfs(a - move, b + move, c);
		if (C - c > 0)
			move = min(a, C - c), dfs(a - move, b, c + move);
	}
	if (b > 0) {
		if (C - c > 0)
			move = min(b, C - c), dfs(a, b - move, c + move);
		if (A - a > 0)
			move = min(b, A - a), dfs(a + move, b - move, c);
	}
	if (c > 0) {
		if (A - a > 0)
			move = min(c, A - a), dfs(a + move, b, c - move);
		if (B - b > 0)
			move = min(c, B - b), dfs(a, b + move, c - move);
	}
}

int main() {
	scanf("%d %d %d", &A, &B, &C);
	dfs(0, 0, C);
	for (int i = 0; i <= C; i++)
		if (visit[0][i])
			printf("%d ", i);
}