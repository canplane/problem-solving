# N^2 : 그런데 이게 더 빠름??? (N = 100으로 충분히 작아서)

import sys
input = lambda: sys.stdin.readline().rstrip()

from collections import deque

T = int(input())
for _ in range(T):
	N, M = map(int, input().split())
	A = list(map(int, input().split()))

	q = deque(enumerate(A))
	cnt = 0
	while len(q) > 0:
		i, x = q.popleft()
		b = True
		for j, y in q:
			if x < y:
				b = False
				break
		if b:
			cnt += 1
			if i == M:
				print(cnt)
				break			
		else:
			q.append([i, x])