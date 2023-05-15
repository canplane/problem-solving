# naive O(N^2) -> O(NlgN)

import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())
A = list(map(int, input().split()))

from bisect import bisect_left
LIS = []

for i in range(N):
	lower_bound = bisect_left(LIS, A[i])
	if lower_bound == len(LIS):
		LIS.append(0)
	LIS[lower_bound] = A[i]

print(len(LIS))