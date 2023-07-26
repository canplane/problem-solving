// BOJ 9252 G4 LCS 2
// LCS: longest common subsequence (최장 공통 부분 수열)
// 오히려 DP보다 역추적에서 막힘: for문 인덱싱 관련해서 구현 오류 주의. (주의력 부족)

using namespace std;
#include <bits/stdc++.h>

char A[1001], B[1001];
int dp[1001][1001];

int main()
{
	scanf("%s %s", A + 1, B + 1);
	int lA = strlen(A + 1), lB = strlen(B + 1);

	for (int i = 1; i < 1 + lA; i++) {
		for (int j = 1; j < 1 + lB; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if (A[i] == B[j]) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
			}
		}
	}
	printf("%d\n", dp[lA][lB]);

	vector<char> ans;
	int i = lA, j = lB;
	while (dp[i][j]) {
		if (dp[i][j - 1] == dp[i][j]) {
			j -= 1;
		}
		else if (dp[i - 1][j] == dp[i][j]) {
			i -= 1;
		}
		else {
			ans.push_back(A[i]);
			i -= 1, j -= 1;
		}
	}
	while (!ans.empty()) {
		printf("%c", ans.back()), ans.pop_back();
	}
}