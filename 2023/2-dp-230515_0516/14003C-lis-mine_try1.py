# mine: 1st trial: linked list

import sys
input = lambda: sys.stdin.readline().rstrip()

from bisect import bisect_left

N = int(input())
A = list(map(int, input().split()))

LIS = []
for i in range(N):
	l = bisect_left(LIS, (A[i], -1, None))
	if l == len(LIS):
		LIS.append((A[i], i, None))
	elif A[i] != LIS[l][0]:
		LIS[l] = (A[i], i, LIS[l])

ans = len(LIS)
seq = [ LIS[-1][0] ]
next = LIS[-1]
for i in range(ans - 1)[::-1]:
	node = LIS[i]
	while node:
		if node[0] < next[0] and node[1] < next[1]:
			break
		node = node[2]
	seq.append(node[0])
	next = node
print(ans)
print(*seq[::-1])