# O(NlgN) (naive: O(N^2))

import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())
A = list(map(int, input().split()))

# bisect.bisect_left()가 더 빠름
LIS = []
lower_bound = None
def bound(l, r, key):
	global lower_bound
	while True:
		if l == r:
			lower_bound = l
			return -1
		
		m = (l + r) // 2
		if key == LIS[m]:
			lower_bound = m
			return m
		else:
			if key < LIS[m]:
				r = m
			else:
				l = m + 1

for i in range(N):
	bound(0, len(LIS), A[i])
	if lower_bound == len(LIS):
		LIS.append(0)
	LIS[lower_bound] = A[i]

print(len(LIS))