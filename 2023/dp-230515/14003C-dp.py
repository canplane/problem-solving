# O(NlgN): binary search + DP

import sys
input = lambda: sys.stdin.readline().rstrip()

from bisect import bisect_left

N = int(input())
A = list(map(int, input().split()))

LIS = []
dp = [ 0 ] * N
for i in range(N):
	l = bisect_left(LIS, A[i])
	if l == len(LIS):
		LIS.append(0)
	LIS[l] = A[i]
	dp[i] = l

ans = len(LIS)
for i in range(N):
	if dp[i] == ans - 1:	break
seq = [ A[i] ]
for j in range(i)[::-1]:
	if dp[j] + 1 == dp[i] and A[j] < A[i]:
		seq.append(A[j])
		if dp[j] == 0:	break
		i = j
print(ans)
print(*seq[::-1])