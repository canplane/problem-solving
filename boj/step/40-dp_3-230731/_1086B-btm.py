# BOJ 1086 P5 박성원

import sys
input = lambda: sys.stdin.readline().rstrip()

from math import factorial, gcd

N = int(input())
A = [ int(input()) for _ in range(N) ]
K = int(input())

R = [ A[i] % K for i in range(N) ]
L = [ 0 for _ in range(1 << N) ]
for i in range(N):
	L[1 << i] = len(str(A[i]))

dp = [ [0] * K for _ in range(1 << N) ]
dp[0][0] = 1
for state in range(1, 1 << N):
	for i in range(N):
		if state & (1 << i):
			dr = (R[i] * (10 ** L[state & ~(1 << i)])) % K
			L[state] = L[1 << i] + L[state & ~(1 << i)]
			for r in range(K):
				dp[state][r] += dp[state & ~(1 << i)][(r - dr + K) % K]

nu = dp[(1 << N) - 1][0]
de = factorial(N)
g = gcd(de, nu)
print(f"{nu // g}/{de // g}")