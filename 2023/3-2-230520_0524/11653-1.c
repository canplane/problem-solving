#include <stdio.h>
#define MAX_N 10000000

char dp[1 + MAX_N];
int prime[MAX_N / 2];

int main()
{
	int i, j, p;

	int N;
	scanf("%d", &N);
	
	dp[0] = dp[1] = 1;
	p = 0;
	for (i = 2; i <= MAX_N; i++) {
		if (dp[i])	continue;
		prime[p++] = i;
		for (j = 2 * i; j <= MAX_N; j += i)
			dp[j] = 1;
	}

	p = 0;
	while (N > 1) {
		for (; N % prime[p]; p++);
		printf("%d\n", prime[p]);
		N /= prime[p];
	}
}