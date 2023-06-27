import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())
A = [ int(input()) for _ in range(N) ]
A.sort()

m = M = A[0]
cur, cur_cnt = A[0], 1
freq1, freq1_cnt = A[0], 1
freq2, freq2_cnt = None, 0
for i in range(1, N):
	if A[i] < m:
		m = A[i]
	if A[i] > M:
		M = A[i]

	if cur == A[i]:
		cur_cnt += 1
	else:
		cur, cur_cnt = A[i], 1
	
	if cur_cnt > freq1_cnt:
		freq1, freq1_cnt = cur, cur_cnt
		freq2, freq2_cnt = None, 0
	elif freq2 == None and cur_cnt == freq1_cnt:
		freq2, freq2_cnt = cur, cur_cnt

import math
print(math.floor(sum(A) / N + 0.5))
print(A[N // 2])
print(freq1 if freq2 == None else freq2)
print(M - m)