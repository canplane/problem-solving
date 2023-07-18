// TLE: 백트래킹 dp는 너무 계산량이 많다.

using namespace std;
#include <bits/stdc++.h>

int N;
int T[1500001], P[1500001];

int dp[1500001];
int bt(int n_i)
{
	if (dp[n_i]) {
		return n_i;
	}

	int ret = 0;
	for (int i = n_i; i <= N; i++) {
		if (i + T[i] <= N + 1) {
			ret = max(ret, P[i] + bt(i + T[i]));
		}
	}
	return dp[n_i] = ret;
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &T[i], &P[i]);
	}
	printf("%d", bt(1));
}