import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *args: sys.stdout.write(f"{' '.join(map(str, args))}\n")
####

def dfs(adj, visit, v):
	visit[v] = True
	for w in adj[v]:
		if visit[w] == False:
			dfs(adj, visit, w)

T = int(input())
for _ in range(T):
	N = int(input())
	A = [0] + list(map(int, input().split()))

	adj = [ [] for _ in range(N + 1) ]
	for v in range(1, N + 1):
		adj[v].append(A[v]); adj[A[v]].append(v)
	
	visit = [ False for _ in range(N + 1) ]
	
	ans = 0
	for v in range(1, N + 1):
		if visit[v] == False:
			ans += 1
			dfs(adj, visit, v)
	print(ans)