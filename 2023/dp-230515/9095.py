import sys
input = lambda: sys.stdin.readline().rstrip()


a = [0] * 12
a[1] = 1; a[2] = 2; a[3] = 4

T = int(input())
for _ in range(T):
	n = int(input())
	for i in range(4, n + 1):
		a[i] = a[i - 1] + a[i - 2] + a[i - 3]
	print(a[n])