# 틀린 이유: Python은 math.round 오류! (round half to even)

import sys
input = lambda: sys.stdin.readline().rstrip()

import math
def _round(x):	return math.floor(x + 0.5)	# OR int((x + 0.5) // 1)

N = int(input())
if N > 0:
	A = [ int(input()) for _ in range(N) ]
	A.sort()
	k = _round(len(A) * 0.15)
	A = A[k:(N - k)]
	print(_round(sum(A) / len(A)))
else:
	print(0)