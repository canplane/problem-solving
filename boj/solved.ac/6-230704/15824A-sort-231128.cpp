// BOJ 15824 G2 너 봄에는 캡사이신이 맛있단다
// 나머지 연산된 거 뺄 때는 음수를 주의해야 함! (2^i % MOD < 2^(i + 1) % MOD일 수 있으니까.)

#include <bits/stdc++.h>

#define M 1000000007

int N;
long A[300000], P[300000];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%ld", &A[i]);
	std::sort(A, A + N);

	P[0] = 1;
	for (int i = 1; i < N; i++)
		P[i] = (P[i - 1] * 2) % M;

	long ans = 0;
	for (int i = 0, j; i < (j = (N - 1) - i); i++)
		ans = (ans + ((P[j] - P[i] + M) * (A[j] - A[i] + M)) % M) % M;
	printf("%ld", ans);
}