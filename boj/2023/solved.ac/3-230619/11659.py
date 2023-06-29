# prefix sum (누적 합)

import sys
input = lambda: sys.stdin.readline().rstrip()

N, M = map(int, input().split())
A = list(map(int, input().split()))
S = [0]
for a in A:
	S.append(S[-1] + a)
for _ in range(M):
	i, j = map(int, input().split())
	print(S[j] - S[i - 1])