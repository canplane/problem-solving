// BOJ 1086 P5 박성원

using namespace std;
#include <bits/stdc++.h>

int N, K;
char s[15][51];

long R[15], WR[15 * 50 + 1];
long L[1 << 15];

long dp[1 << 15][100];

long fact(int n)
{
	long ret = 1;
	do {
		ret *= n;
	} while (--n);
	return ret;
}
long gcd(long a, long b)
{
	long t;
	while (b) {
		t = a, a = b, b = t % b;
	}
	return a;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", s[i]);
	}
	scanf("%d", &K);

	for (int i = 0; i < N; i++) {
		int j;
		for (j = 0; s[i][j]; j++) {
			R[i] = (R[i] * 10 + (s[i][j] - '0')) % K;
		}
		L[1 << i] = j;
	}
	WR[0] = 1;
	for (int i = 1; i <= 15 * 50; i++) {
		WR[i] = (WR[i - 1] * 10) % K;
	}

	dp[0][0] = 1;
	for (long state = 1; state < (1 << N); state++) {
		for (int i = 0; i < N; i++) {
			if (state & (1 << i)) {
				long dr = (R[i] * WR[L[state & ~(1 << i)]]) % K;
				L[state] = L[1 << i] + L[state & ~(1 << i)];
				for (int r = 0; r < K; r++) {
					dp[state][r] += dp[state & ~(1 << i)][(r - dr + K) % K];
				}
			}
		}
	}

	long nu = dp[(1 << N) - 1][0], de = fact(N);
	long g = gcd(de, nu);
	printf("%ld/%ld", nu / g, de / g);
}