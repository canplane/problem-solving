# naive O(N^2) -> O(NlgN)

import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())
A = list(map(int, input().split()))

from bisect import bisect_left
bs = []

for i in range(N):
	lower_bound = bisect_left(bs, A[i])
	if lower_bound == len(bs):
		bs.append(A[i])
	else:
		bs[lower_bound] = A[i]

print(len(bs))