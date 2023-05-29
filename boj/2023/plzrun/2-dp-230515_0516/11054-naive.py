import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())
A = list(map(int, input().split()))

# O(N^2): naive
def f():
	dp = [ 0 ] * N
	for i in range(N):
		for j in range(i)[::-1]:
			if A[j] < A[i]:
				dp[i] = max(dp[i], dp[j])
		dp[i] += 1
	return dp
dp1 = f()
A = A[::-1]; dp2 = f()[::-1]

ans = 0
for i in range(N):
	ans = max(ans, dp1[i] + dp2[i])
print(ans - 1)