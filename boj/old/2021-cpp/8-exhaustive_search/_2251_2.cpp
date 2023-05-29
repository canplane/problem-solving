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
	move = min(a, B - b), dfs(a - move, b + move, c);
	move = min(a, C - c), dfs(a - move, b, c + move);
	move = min(b, C - c), dfs(a, b - move, c + move);
	move = min(b, A - a), dfs(a + move, b - move, c);
	move = min(c, A - a), dfs(a + move, b, c - move);
	move = min(c, B - b), dfs(a, b + move, c - move);
}

int main() {
	scanf("%d %d %d", &A, &B, &C);
	dfs(0, 0, C);
	for (int i = 0; i <= C; i++)
		if (visit[0][i])
			printf("%d ", i);
}