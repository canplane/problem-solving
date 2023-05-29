import sys
input = lambda: sys.stdin.readline().rstrip()

n = int(input())
A = [ int(input()) for _ in range(n) ] + [ 0, 0, 0 ]
a = [0] * (n + 3)

for i in range(n):
	a[i] = max(
		(A[i] + A[i - 1]) + a[i - 3],
		(A[i]) + a[i - 2],
		a[i - 1],
	)
print(a[n - 1])