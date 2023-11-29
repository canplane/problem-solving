// BOJ 1019 G1 책 페이지
// 직접 점화식 만들어서 해결했다.
// e.g., 357까지의 수: cnt(1, 358) = cnt(1, 100) + (100 I1 + cnt(0, 100)) + (100 I2 + cnt(0, 100)) + (58 I3 + cnt(0, 58))

using namespace std;
#include <bits/stdc++.h>

long P[10];
long dp[10][10];

long C[10];
void cnt(bool l, long r, int w)
{
	if (w >= 0) {
		long d = r / P[w];

		for (int i = l; i < d; i++)
			C[i] += P[w];

		if (l)
			cnt(1, P[w], w - 1);
		if (w >= 1)
			for (int i = 0; i < 10; i++)
				C[i] += (d - l) * dp[w - 1][i];

		r = r % P[w];
		if (r > 0)
			C[d] += r, cnt(0, r, w - 1);
	}
}

int main()
{
	long N;
	scanf("%ld", &N);

	P[0] = 1;
	for (int i = 1; i < 10; i++)
		P[i] = P[i - 1] * 10;

	for (int i = 0; i < 10; i++)
		dp[0][i] = 1;
	for (int w = 1; w < 10; w++)
		for (int i = 0; i < 10; i++)
			dp[w][i] += P[w] + 10 * dp[w - 1][i];
	
	int w;
	for (w = 0; w < 10; w++)
		if (N < 10 * P[w])
			break;

	cnt(1, N + 1, w);
	for (long e : C)
		printf("%ld ", e);
}