using namespace std;
#include <cstdio>
#include <algorithm>
#include <cmath>

#define INF 0x7fffffff
#define OTHER(team, N) (~(team) & ((1 << (N)) - 1))

int N;
int A[20][20], S[1 << 20];

int team, score;
int combi(int n_i, int r_i)
{
	if (r_i == N / 2) {
		S[team] = score;
		return S[OTHER(team, N)] ? abs(S[team] - S[OTHER(team, N)]) : INF;
	}

	int ret = INF;
	for (int i = n_i; i < N; i++) {
		int dscore = 0;
		for (int j = 0; j < i; j++) {
			if (team & (1 << j)) {
				dscore += A[i][j];
			}
		}
		team |= (1 << i), score += dscore;
		ret = min(ret, combi(i + 1, r_i + 1));
		team &= ~(1 << i), score -= dscore;
	}
	return ret;
}

int main()
{
	scanf("%d", &N);
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf("%d", &A[y][x]);
			if (y > x) {
				A[y][x] += A[x][y];
			}
		}
	}
	printf("%d", combi(0, 0));
}