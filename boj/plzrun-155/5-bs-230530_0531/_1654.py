import sys
input = lambda: sys.stdin.readline().rstrip()

A = []
K, N = map(int, input().split())
for i in range(K):
	A.append(int(input()))

def upper_bound(lo, hi):
	while (lo < hi):
		mi = lo + (hi - lo) // 2
		pieces = sum(a // mi for a in A)
		if (pieces < N):
			hi = mi
		else:
			lo = mi + 1
	return lo
print(upper_bound(1, max(A) + 1) - 1)