// 조합은 prev_permutation을 이용해서 구할 수도 있음! (최적화 안 하면 직접 짠 것과 소요 시간 동일)

using namespace std;
#include <cstdio>
#include <algorithm>
#include <cmath>

#define INF 0x7fffffff

int N;
int A[20][20];

bool team[20];
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

	int ans = INF;
	for (int i = 0; i < N / 2; i++) {
		team[i] = true;
	}
	do {
		int score[2] = { 0, 0 };
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < i; j++) {
				if (team[i] == team[j]) {
					score[team[i]] += A[i][j];
				}
			}
		}
		ans = min(ans, abs(score[1] - score[0]));
	} while (prev_permutation(team, team + N));
	
	printf("%d", ans);
}