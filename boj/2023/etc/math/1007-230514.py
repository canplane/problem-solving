import sys
input = lambda: sys.stdin.readline().rstrip()

from itertools import combinations

T = int(input())
for _ in range(T):
	N = int(input())

	x, y = [ [ None ] * N for _ in range(2) ]
	for i in range(N):
		x[i], y[i] = map(int, input().split())

	
	combs = list(combinations(range(N), N // 2))
	X, Y = sum(x), sum(y)

	ans = 1e20
	for comb in combs:
		X1, Y1 = sum([ x[i] for i in comb ]), sum([ y[i] for i in comb ])
		X2, Y2 = X - X1, Y - Y1
		ans = min(ans, (X1 - X2) ** 2 + (Y1 - Y2) ** 2)
	print(ans ** (1 / 2))