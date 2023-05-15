# mine: 2nd trial: prev link

import sys
input = lambda: sys.stdin.readline().rstrip()

from bisect import bisect_left

N = int(input())
A = list(map(int, input().split()))

LIS = []
prev = [ -1 ] * N
for i in range(N):
	l = bisect_left(LIS, (A[i], 0))
	if l == len(LIS):
		LIS.append((A[i], i))
		prev[i] = LIS[l - 1][1] if l > 0 else -1
	elif A[i] != LIS[l][0]:
		LIS[l] = (A[i], i)
		prev[i] = LIS[l - 1][1] if l > 0 else -1

ans = len(LIS)
seq = []
i = LIS[-1][1]
while i != -1:
	seq.append(A[i])
	i = prev[i]
print(ans)
print(*seq[::-1])