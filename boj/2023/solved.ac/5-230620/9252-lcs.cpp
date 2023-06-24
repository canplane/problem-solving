// LCS: longest common subsequence (최장 공통 부분 수열)
// 오히려 DP보다 역추적에서 막힘: for문 인덱싱 관련해서 구현 오류 심함. (주의력 부족)

using namespace std;
#include <cstdio>
#include <algorithm>

char A[1002], B[1002];

int dp[1001][1001];
char C[1001];

int main()
{
	scanf("%s %s", A + 1, B + 1);
	
	int i, j;
	for (i = 1; A[i]; i++) {
		for (j = 1; B[j]; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if (A[i] == B[j]) {
				dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1]);
			}
		}
	}
	i--, j--;

	printf("%d\n", dp[i][j]);
	if (dp[i][j]) {
		int k = 0;
		while (i >= 1 && j >= 1) {
			if (A[i] == B[j]) {
				C[k++] = A[i];
				i--, j--;
			}
			else {
				if (i > 1 && dp[i - 1][j] == dp[i][j]) {
					i--;
				}
				else {
					j--;
				}
			}
		}
		while (k--) {
			printf("%c", C[k]);
		}
	}
}