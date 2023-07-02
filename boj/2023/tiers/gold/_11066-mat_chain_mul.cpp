// matrix chain multiplication (연쇄 행렬 곱셈)과 비슷

using namespace std;
#include <cstdio>
#include <algorithm>

#define INF 0x7fffffff

int K;
int A[501], S[501], dp[501][501];

int f()
{
	for (int di = 1; di <= K; di++) {
		for (int i = 1; i <= K; i++) {
			int j = i + di;
			if (j <= K) {
				dp[i][j] = INF;
				for (int k = i; k + 1 <= j; k++) {
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + (S[j] - S[i - 1]));
				}
			}
		}
	}
	return dp[1][K];
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &K);
		for (int i = 1; i <= K; i++) {
			scanf("%d", &A[i]);
			S[i] = S[i - 1] + A[i];
		}
		printf("%d\n", f());
	}
}