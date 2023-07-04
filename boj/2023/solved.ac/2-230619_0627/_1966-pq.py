# NlgN : 그런데 이게 더 느림??? (N = 100으로 충분히 작아서)

import sys
input = lambda: sys.stdin.readline().rstrip()

from collections import deque
import heapq

T = int(input())
for _ in range(T):
	N, M = map(int, input().split())
	A = list(map(int, input().split()))

	q = deque([-x, i] for i, x in enumerate(A))

	pq = [ -x for x in A.copy() ]
	heapq.heapify(pq)

	seq = 0
	while len(q) > 0:
		x, i = q.popleft()
		if x == pq[0]:
			heapq.heappop(pq)
			seq += 1
			if i == M:
				print(seq)
				break
		else:
			q.append([x, i])