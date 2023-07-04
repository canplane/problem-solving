N, M = map(int, input().split())

A = list(range(1, N + 1))

perm = [None] * M
visit = [False] * N
def permut(r_i):
	if r_i == M:
		print(*perm)
		return    
	for i in range(N):
		if not visit[i]:
			visit[i] = True
			perm[r_i] = A[i]
			permut(r_i + 1)
			visit[i] = False
permut(0)