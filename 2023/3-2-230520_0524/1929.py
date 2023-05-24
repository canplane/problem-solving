M, N = map(int, input().split())

dp = [0] * (N + 1)
dp[0] = dp[1] = 1
for i in range(2, N + 1):
	if dp[i] == 0:
		for j in range(2 * i, N + 1, i):
			dp[j] = 1

for i in range(M, N + 1):
	if dp[i] == 0:
		print(i)