N = int(input())

dp = [0] * (1 + N)
for i in range(1, 1 + N):
	dp[i] = min([ dp[i - x * x] for x in range(1, int(i ** (1 / 2)) + 1) ]) + 1
print(dp[N])