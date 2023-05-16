import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())

a = [0] * (N + 1)
a[1] = 0
for i in range(2, N + 1):
	a[i] = min(a[i // 2] + i % 2, a[i // 3] + i % 3) + 1
print(a[N])