import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())
A = [int(input()) for _ in range(N)] + [0]

dp = [0] * (N + 3)
for i in range(N):
	dp[i] = max(A[i] + A[i - 1] + dp[i - 3], A[i] + dp[i - 2])
print(dp[N - 1])