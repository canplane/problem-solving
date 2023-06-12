dp = [0] * 1001
dp[0] = dp[1] = 1
for i in range(2, 1001):
	if dp[i] == 0:
		for j in range(2 * i, 1001, i):
			dp[j] = 1

N = int(input())
A = list(map(int, input().split()))
print(sum(dp[a] == 0 for a in A))