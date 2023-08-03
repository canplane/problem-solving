// BOJ 17069 G4 파이프 옮기기 2
// 17070의 단순 변형

using namespace std;
#include <bits/stdc++.h>

int N;
int A[33][33];

long dp[33][33][3];

// dir: (0, '-'), (1, '\'), (2, '|')
long bt(int y, int x, int dir)
{
	if (dp[y][x][dir] != -1) {
		return dp[y][x][dir];
	}
	if (y == N && x == N) {
		return dp[y][x][dir] = 1;
	}

	long ret = 0;
	if (dir == 0) {
		if (x + 1 <= N && !A[y][x + 1]) {
			ret += bt(y, x + 1, 0);
		}
		if (y + 1 <= N && x + 1 <= N && !A[y + 1][x + 1] && !A[y][x + 1] && !A[y + 1][x]) {
			ret += bt(y + 1, x + 1, 1);
		}
	}
	else if (dir == 1) {
		if (x + 1 <= N && !A[y][x + 1]) {
			ret += bt(y, x + 1, 0);
		}
		if (y + 1 <= N && x + 1 <= N && !A[y + 1][x + 1] && !A[y][x + 1] && !A[y + 1][x]) {
			ret += bt(y + 1, x + 1, 1);
		}
		if (y + 1 <= N && !A[y + 1][x]) {
			ret += bt(y + 1, x, 2);
		}
	}
	else {
		if (y + 1 <= N && x + 1 <= N && !A[y + 1][x + 1] && !A[y][x + 1] && !A[y + 1][x]) {
			ret += bt(y + 1, x + 1, 1);
		}
		if (y + 1 <= N && !A[y + 1][x]) {
			ret += bt(y + 1, x, 2);
		}
	}
	return dp[y][x][dir] = ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));

	scanf("%d", &N);
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			scanf("%d", &A[y][x]);
		}
	}
	printf("%ld", bt(1, 2, 0));
}