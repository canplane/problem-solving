using namespace std;
#include <cstdio>
#include <algorithm>
#include <cmath>

#define INF 0x7fffffff

int N;
int A[20][20];

bool team[20];
int f()
{
	int score[2] = { 0, 0 };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (team[i] == team[j]) {
				score[team[i]] += A[i][j] + A[j][i];
			}
		}
	}
	return abs(score[1] - score[0]);
}
int combi(int n_i, int r_i)
{
	if (r_i == N / 2) {
		return f();
	}
	int ret = INF;
	for (int i = n_i; i < N; i++) {
		team[i] = true;
		ret = min(ret, combi(i + 1, r_i + 1));
		team[i] = false;
	}
	return ret;
}

int main()
{
	scanf("%d", &N);
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf("%d", &A[y][x]);
		}
	}
	printf("%d", combi(0, 0));
}