// BOJ 17404 G4 RGB거리 2
// 원형 DP

using namespace std;
#include <bits/stdc++.h>

uint N, A[1001][3], D[1001][3];
int f(int c)
{
	uint t;
	D[0][0] = D[0][1] = D[0][2] = -1, D[0][c] = A[0][c];
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < 3; j++)
			D[i][j] = (t = min(D[i - 1][(j + 1) % 3], D[i - 1][(j + 2) % 3])) != -1 ? A[i][j] + t : -1;
	return D[N][c];
}
int main()
{
	scanf("%u", &N);
	for (int i = 0; i < N; i++)
		scanf("%u %u %u", &A[i][0], &A[i][1], &A[i][2]);
	printf("%u", min(min(f(0), f(1)), f(2)));
}