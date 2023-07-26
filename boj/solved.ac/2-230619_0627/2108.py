import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())
A = [ int(input()) for _ in range(N) ]
A.sort()

freq = {}
m = M = A[0]
for i in range(N):
	if A[i] < m:
		m = A[i]
	if A[i] > M:
		M = A[i]
	if A[i] not in freq:
		freq[A[i]] = 0
	freq[A[i]] += 1
freq = [ [-v, k] for k, v in freq.items() ]
freq.sort()
freq = freq[1 if len(freq) > 1 and freq[0][0] == freq[1][0] else 0][1]  

import math
print(math.floor(sum(A) / N + 0.5))
print(A[N // 2])
print(freq)
print(M - m)