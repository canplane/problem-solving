using namespace std;
#include <bits/stdc++.h>

int N;
int A[1000];
int dp[1000];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = i - 1; j >= 0; j--) {
			if (A[j] < A[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		} 
	}

	int ans = dp[0];
	for (int i = 0; i < N; i++) {
		ans = max(ans, dp[i]);
	}
	printf("%d", ans);
}