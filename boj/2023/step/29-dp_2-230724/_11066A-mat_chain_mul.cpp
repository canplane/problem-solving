// BOJ 11066 G3 파일 합치기
// matrix chain multiplication (연쇄 행렬 곱셈)과 비슷

using namespace std;
#include <bits/stdc++.h>

int N;
int S[501];
int dp[501][501];

void sol()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int x;
		scanf("%d", &x);
		S[i] = S[i - 1] + x;
	}

	for (int di = 1; di <= N - 1; di++) {
		int j;
		for (int i = 1; (j = i + di) <= N; i++) {
			dp[i][j] = INT_MAX;
			for (int k = i; k + 1 <= j; k++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + S[j] - S[i - 1]);
			}
		}
	}
	printf("%d\n", dp[1][N]);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		sol();
	}
}