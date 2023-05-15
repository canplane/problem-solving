import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())
A = [0] + list(map(int, input().split()))

dp = [ 0 ] * (N + 1)
for i in range(1, N + 1):
    dp[i] = A[i] + max(0, dp[i - 1])
print(max(dp[1:]))