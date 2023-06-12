/*
	1시간 반이나 걸림. 이전꺼 보고 풀음.
	틀린 이유:
		문제 이해 잘못.
			1. 1 <= k <= K인 k 모두 이동 가능하다는 것 모름
			2. 재방문 가능하다는 것 모름
*/

using namespace std;
#include <cstdio>
#include <cstring>

int N, M, K;
char A[100][101];
int memo[100][100][80];

char s[81];

int dy[4] = { -1, 0, 0, 1 };
int dx[4] = { 0, -1, 1, 0 };
int dfs(int y, int x, int idx) {
	if (!s[idx + 1]) {
		return 1;
	}

	int ret = 0;
	for (int i = 0; i < 4; i++) {
		for (int k = 1; k <= K; k++) {
			int ny = y + k * dy[i];
			int nx = x + k * dx[i];
			if (!(0 <= ny && ny < N && 0 <= nx && nx < M))
				continue;
			if (A[ny][nx] == s[idx + 1]) {
				if (memo[ny][nx][idx + 1] == -1)
					memo[ny][nx][idx + 1] = dfs(ny, nx, idx + 1);
				ret += memo[ny][nx][idx + 1];
			}
		}
	}
	return ret;
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);
	for (int y = 0; y < N; y++) {
		scanf("%s", A[y]);
	}
	scanf("%s", s);

	memset(memo, -1, sizeof(memo));

	int ans = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (A[y][x] == s[0]) {
				ans += dfs(y, x, 0);
			}
		}
	}
	printf("%d", ans);
}