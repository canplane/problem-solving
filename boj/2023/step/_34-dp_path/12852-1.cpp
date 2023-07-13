#include <cstdio>

int dp[1000001], pre[1000001];

int main()
{
	int X, t, s;
	scanf("%d", &X);

	for (int i = 2; i <= X; i++) {
		dp[i] = dp[i - 1] + 1, pre[i] = i - 1;
		if (!(i % 2) && (t = dp[s = i / 2] + 1) < dp[i]) {
			dp[i] = t, pre[i] = s;
		}
		if (!(i % 3) && (t = dp[s = i / 3] + 1) < dp[i]) {
			dp[i] = t, pre[i] = s;
		}
	}
	printf("%d\n", dp[X]);
	printf("%d ", X);
	while (X > 1) {
		printf("%d ", X = pre[X]);
	}
}