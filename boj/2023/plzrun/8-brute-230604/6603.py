import sys
input = lambda: sys.stdin.readline().rstrip()

def combi(n, n_i, r, r_i):
	global A, _combi
	if r_i == r:
		print(*_combi)
		return
	for i in range(n_i, n):
		_combi[r_i] = A[i]
		combi(n, i + 1, r, r_i + 1)

while True:
	A = list(map(int, input().split()))
	if A[0] == 0:
		break
	A = A[1:]
	_combi = [None] * 6
	combi(len(A), 0, 6, 0)
	print()
