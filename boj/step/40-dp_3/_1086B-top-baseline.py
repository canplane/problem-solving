# 이거 베이스로 top down하려 했더니 dp 엮기가 어려워서 bottom up으로 짬

import sys
input = lambda: sys.stdin.readline().rstrip()

def dfs(dep, num, weight):
	global N, cnt, ans
	if dep == N:
		cnt += 1
		ans += (num % K == 0)
		return

	for v in range(N):
		if not vis[v]:
			vis[v] = True
			dfs(dep + 1, A[v] * (10 ** weight) + num, L[v] + weight)
			vis[v] = False
	

N = int(input())
A = [ int(input()) for _ in range(N) ]
K = int(input())

R = [ A[i] % K for i in range(N) ]
L = [ len(str(A[i])) for i in range(N) ]

vis = [False] * N
cnt, ans = 0, 0
dfs(0, 0, 0)

from math import gcd
g = gcd(cnt, ans)
cnt //= g; ans //= g
print(f"{ans}/{cnt}")
