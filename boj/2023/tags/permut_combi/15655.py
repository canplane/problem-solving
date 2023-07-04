N, M = map(int, input().split())

A = list(map(int, input().split()))
A.sort()

comb = [None] * M
def combi(n_i, r_i):
	if r_i == M:
		print(*comb)
		return
	for i in range(n_i, N):
		comb[r_i] = A[i]
		combi(i + 1, r_i + 1)
combi(0, 0)