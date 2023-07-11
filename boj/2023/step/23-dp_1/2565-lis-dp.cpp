// LIS: longest increasing subsequence (plain DP ver.)

using namespace std;
#include <cstdio>
#include <algorithm>

int N;
int A[501];
int dp[501];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		A[x] = y;
	}

	int ans = 0;
	for (int i = 1; i <= 500; i++) {
		if (!A[i])	continue;
		dp[i] = 1;
		for (int j = i - 1; j > 0; j--) {
			if (!A[j])	continue;
			if (A[j] < A[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);
	}
	printf("%d", N - ans);
}