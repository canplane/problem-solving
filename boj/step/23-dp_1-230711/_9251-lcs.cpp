// BOJ 9251 G5 LCS
// LCS: longest common subsequence (최장 공통 부분 수열)

using namespace std;
#include <bits/stdc++.h>

char A[1002], B[1002];
int dp[1002][1002];

int main()
{
	scanf("%s %s", A + 1, B + 1);

	int i, j;
	for (i = 1; A[i]; i++) {
		for (j = 1; B[j]; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if (A[i] == B[j]) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
			}
		}
	}
	printf("%d", dp[i - 1][j - 1]);
}