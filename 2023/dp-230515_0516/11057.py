import sys
input = lambda: sys.stdin.readline().rstrip()


N = int(input())

a = [ [1] * 10 for _ in range(N + 1) ]
for i in range(2, N + 1):
	a[i][0] = a[i - 1][0]
	for j in range(1, 10):
		a[i][j] = (a[i][j - 1] + a[i - 1][j]) % 10007
print(sum(a[N]) % 10007)