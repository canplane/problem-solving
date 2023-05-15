import sys
input = lambda: sys.stdin.readline().rstrip()

T = int(input())
for _ in range(T):
	N = int(input())
	A = [ [0] + list(map(int, input().split())) for _ in range(2) ]

	a0, a1 = [ [ 0 ] * (N + 1) for _ in range(2) ] 
	a0[1], a1[1] = A[0][1], A[1][1]
	for i in range(2, N + 1):
		a0[i] = A[0][i] + max(a1[i - 1], a1[i - 2])
		a1[i] = A[1][i] + max(a0[i - 1], a0[i - 2])
	print(max(a0[N], a1[N]))