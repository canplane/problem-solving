# fast io required!!!
import sys
input = lambda: sys.stdin.readline().rstrip()

from collections import deque

T = int(input())
for _ in range(T):
	N, K = map(int, input().split())
	D = [ 0 ] + list(map(int, input().split()))
	edges = [ [] for _ in range(N + 1) ]
	in_degree = [ 0 for _ in range(N + 1) ]
	for _ in range(K):
		a, b = map(int, input().split())
		edges[a].append(b)
		in_degree[b] += 1
	W = int(input())

	dist = [ -1 for _ in range(N + 1) ]
	q = deque(maxlen=N)
	for a in range(1, N + 1):
		if in_degree[a] == 0:
			q.append(a)
			dist[a] = D[a]
	while len(q) > 0:
		if (a := q.popleft()) == W:
			break
		for b in edges[a]:
			in_degree[b] -= 1
			if in_degree[b] == 0:
				q.append(b)
			dist[b] = max(dist[b], dist[a] + D[b])
	print(dist[W])