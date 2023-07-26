# 파이썬이 느려서 올바르게 짜도 시간 초과가 남. (PyPy 말고는 답 없음)

import sys
input = lambda: sys.stdin.readline().rstrip()

from math import inf

N, M, B = map(int, input().split())
H = [ list(map(int, input().split())) for _ in range(N) ]

def f(h):
	lo, hi = 0, 0
	for y in range(N):
		for x in range(M):
			if H[y][x] <= h:
				lo += h - H[y][x]
			else:
				hi += H[y][x] - h
	return lo + 2 * hi if B + hi - lo >= 0 else inf

ans_t, ans_h = inf, None
for h in range(256, -1, -1):
	t = f(h)
	if t < ans_t:
		ans_t, ans_h = t, h
print(ans_t, ans_h)