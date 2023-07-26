// 마지막부터 시작해서 처음으로 내려오는 DP!!

using namespace std;
#include <bits/stdc++.h>

#define N_MAX 1500000
#define T_MAX 50

int N;
int T[N_MAX + 1], P[N_MAX + 1];

int dp[N_MAX + 2];	// dp[i] : [i, N]에서의 최대 수익 : 뒤에서 앞으로 간다.

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &T[i], &P[i]);
	}

	for (int i = N; i >= 1; i--) {
		if (i + T[i] <= N + 1) {
			dp[i] = max(dp[i + 1], P[i] + dp[i + T[i]]);
		}
		else {
			dp[i] = dp[i + 1];
		}
	}
	printf("%d", dp[1]);
}