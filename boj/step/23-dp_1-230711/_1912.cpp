// BOJ 1912 S2 연속합

using namespace std;
#include <bits/stdc++.h>

int n;
int A[100000];
int dp[100000];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}

	int ans = dp[0] = A[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + A[i], A[i]);
		ans = max(ans, dp[i]);
	}
	printf("%d", ans);
}