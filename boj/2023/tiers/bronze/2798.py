import sys
input = lambda: sys.stdin.readline().rstrip()

N, M = map(int, input().split())
A = list(map(int, input().split()))

from itertools import combinations
combs = list(combinations(A, 3))

ans = 0
for comb in combs:
	if sum(comb) > M:
		continue
	ans = max(ans, sum(comb))
print(ans)