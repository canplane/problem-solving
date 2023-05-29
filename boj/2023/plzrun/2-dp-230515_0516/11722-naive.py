import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())
A = list(map(int, input().split()))

# O(N^2): naive
dp = [ 0 ] * N
for i in range(N)[::-1]:
    for j in range(i + 1, N):
        if A[j] < A[i]:
            dp[i] = max(dp[i], dp[j])
    dp[i] += 1

print(max(dp))