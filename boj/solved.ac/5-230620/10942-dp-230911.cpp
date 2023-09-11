// BOJ 10942 G4 팰린드롬?
// 10 mins

using namespace std;
#include <bits/stdc++.h>

int N;
int A[2001];
bool dp[2001][2001];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	int j;
	for (int i = 0; i < N; i++) {
		dp[i][i] = true;
	}
	for (int i = 0; (j = i + 1) < N; i++) {
		dp[i][j] = (A[i] == A[j]);
	}
	for (int di = 2; di < N; di++) {
		for (int i = 0; (j = i + di) < N; i++) {
			dp[i][j] = dp[i + 1][j - 1] && (A[i] == A[j]);
		}
	}

	int M;
	scanf("%d", &M);
	while (M--) {
		int i, j;
		scanf("%d %d", &i, &j);
		printf("%d\n", dp[i - 1][j - 1]);
	}
}