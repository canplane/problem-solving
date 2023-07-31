// BOJ 2482 G3 색상환
// top-down이 역시 개구리다. (4 vs 908 ms)

using namespace std;
#include <bits/stdc++.h>

#define MOD 1000000003

int N, K;
long dp1[1003][1001], dp2[1003][1001];
long bt(int l, int r, int cnt, long dp[][1001])
{
	if (dp[l][cnt] != -1) {
		return dp[l][cnt];
	}
	if (cnt == 0) {
		return dp[l][cnt] = 1;
	}

	long ret = 0;
	for (int i = l; i < r; i++) {
		ret = (ret + bt(i + 2, r, cnt - 1, dp)) % MOD;
	}
	return dp[l][cnt] = ret;
}
int main()
{
	memset(dp1, -1, sizeof(dp1)), memset(dp2, -1, sizeof(dp2));
	scanf("%d %d", &N, &K);
	// 0번지를 포함했을 때, 하지 않았을 때
	printf("%ld", (bt(2, N - 1, K - 1, dp1) + bt(1, N, K, dp2)) % MOD);
}