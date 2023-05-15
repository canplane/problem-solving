N = int(input())

dp = [0] * (N + 1)
for i in range(1, N + 1):
	# 이렇게 한 번에 init하는 게 빠름
	dp[i] = min([ 1 + dp[i - j ** 2] for j in range(1, int(i ** (1 / 2)) + 1) ])
print(dp[N])