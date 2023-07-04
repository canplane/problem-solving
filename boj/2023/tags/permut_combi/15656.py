N, M = map(int, input().split())

A = list(map(int, input().split()))
A.sort()

perm = [None] * M
def permut_rep(r_i):
	if r_i == M:
		print(*perm)
		return    
	for i in range(N):
		perm[r_i] = A[i]
		permut_rep(r_i + 1)
permut_rep(0)