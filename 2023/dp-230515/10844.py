import sys
input = lambda: sys.stdin.readline().rstrip()


N = int(input())

a = [ [ 0 for _ in range(10) ] for _ in range(N + 1) ]
a[1] = [ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 ]

for i in range(2, N + 1):
	a[i][0] = a[i - 1][1]
	for j in range(1, 9):
		a[i][j] = (a[i - 1][j - 1] + a[i - 1][j + 1]) % 1000000000
	a[i][9] = a[i - 1][8]

print(sum(a[N]) % 1000000000)