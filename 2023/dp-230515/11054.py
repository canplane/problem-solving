import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())
A = list(map(int, input().split()))

from bisect import bisect_left

# O(NlgN): not naive
def f():
	LIS = []; dp = [ 0 ] * N
	for i in range(N):
		l = bisect_left(LIS, A[i])
		if l == len(LIS):
			LIS.append(0)
		LIS[l] = A[i]; dp[i] = l
	return dp
dp1 = f()
A = A[::-1]; dp2 = f()[::-1]

ans = 0
for i in range(N):
	ans = max(ans, dp1[i] + dp2[i])
print(ans + 1)