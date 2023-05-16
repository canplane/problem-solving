import sys
input = lambda: sys.stdin.readline().rstrip()

dp = [ 0 ] + [ 1, 1, 1, 2, 2 ]

T = int(input())
for _ in range(T):
	N = int(input())
	if N >= len(dp):
		for i in range(len(dp), N + 1):
			dp.append(dp[i - 1] + dp[i - 5])
	print(dp[N])