import sys
input = lambda: sys.stdin.readline().rstrip()


N = int(input())
P = [0] + list(map(int, input().split()))

dp = [0] * (1 + N)
for i in range(1, 1 + N):
	dp[i] = max([ P[k] + dp[i - k] for k in range(1, 1 + i) ])
print(dp[N])