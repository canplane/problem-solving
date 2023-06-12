import sys
input = lambda: sys.stdin.readline().rstrip()

def f(a):
	s, n = [], len(a)
	s.append(0)
	for i in range(n):
		s.append(s[-1] + a[i])
	ret = []
	for i in range(n + 1):
		for j in range(i + 1, n + 1):
			ret.append(s[j] - s[i])
	return ret

T = int(input())
n, A = int(input()), list(map(int, input().split()))
m, B = int(input()), list(map(int, input().split()))
fA, fB = f(A), f(B)
fB.sort()

from bisect import bisect_left, bisect_right
cnt = 0
for x in fA:
	cnt += bisect_right(fB, T - x) - bisect_left(fB, T - x)
print(cnt)