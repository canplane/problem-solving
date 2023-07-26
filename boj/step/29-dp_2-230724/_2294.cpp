using namespace std;
#include <bits/stdc++.h>

int n, k;
int A[101];
uint dp[10001];

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
	}

	memset(dp, -1, sizeof(dp));
	
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = A[i]; j <= k; j++) {
			if (dp[j - A[i]] != -1) {
				dp[j] = min(dp[j], dp[j - A[i]] + 1);
			}
		}
	}
	printf("%d", dp[k]);
}