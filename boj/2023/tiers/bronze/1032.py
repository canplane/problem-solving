import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())
A = list(input())
for _ in range(N - 1):
	for i, c in enumerate(input()):
		if A[i] != c:
			A[i] = '?'
print("".join(A))