// 처음부터 채우는 식으로 짠 코드: 에러도 나기 쉽고, 2중 반복이라 뒤부터 내려오는 것보다 비효율적!!

using namespace std;
#include <bits/stdc++.h>

#define N_MAX 1500000
#define T_MAX 50

int N;
int T[N_MAX + 1], P[N_MAX + 1];

int dp[N_MAX + 2];	// dp[i] : (1 ~ i - 1)에서의 최대 수익

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &T[i], &P[i]);
	}

	for (int i = 1; i <= N + 1; i++) {
		for (int j = max(i - T_MAX, 0); j < i; j++) {
			dp[i] = max(dp[i], dp[j] + (j + T[j] <= i ? P[j] : 0));
		}
	}
	printf("%d", dp[N + 1]);
}