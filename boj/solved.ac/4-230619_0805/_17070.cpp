// BOJ 17070 G5 파이프 옮기기 1
// 백트래킹인데 dp인 줄은 생각 못하고 태그 보고 알음. 모르고 제출했으면 시간 초과 났을 듯.
// -> 아님 시간 초과 안 남. 시간 초과 나는 건 17069 

using namespace std;
#include <bits/stdc++.h>

int N;
int A[17][17];

// dir: (0, '-'), (1, '\'), (2, '|')
int bt(int y, int x, int dir)
{
	if (y == N && x == N) {
		return 1;
	}

	int ret = 0;
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
	return ret;
}
int main()
{
	scanf("%d", &N);
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			scanf("%d", &A[y][x]);
		}
	}
	printf("%d", bt(1, 2, 0));
}