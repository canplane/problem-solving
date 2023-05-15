# fast io required!!!
import sys
input = lambda: sys.stdin.readline().rstrip()

def dfs(b):		# RecursionError
	if len(inv_edges[b]) == 0:
		dist[b] = D[b]
	for a in inv_edges[b]:
		if dist[a] == -1:
			dfs(a)
		dist[b] = max(dist[b], dist[a] + D[b])

T = int(input())
for _ in range(T):
	N, K = map(int, input().split())
	D = [ 0 ] + list(map(int, input().split()))
	inv_edges = [ [] for _ in range(N + 1) ]
	for _ in range(K):
		a, b = map(int, input().split())
		inv_edges[b].append(a)
	W = int(input())

	dist = [ -1 for _ in range(N + 1) ]
	dfs(W)
	print(dist[W])