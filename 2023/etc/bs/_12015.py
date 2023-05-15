# naive O(N^2) -> O(NlgN)

import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())
A = list(map(int, input().split()))

bs = []
lower_bound = None
def bound(l, r, key):
	global lower_bound
	while True:
		if l == r:
			lower_bound = l
			return -1
		
		m = (l + r) // 2
		if key == bs[m]:
			lower_bound = m
			return m
		else:
			if key < bs[m]:
				r = m
			else:
				l = m + 1

for i in range(N):
	bound(0, len(bs), A[i])
	if lower_bound == len(bs):
		bs.append(A[i])
	else:
		bs[lower_bound] = A[i]

print(len(bs))