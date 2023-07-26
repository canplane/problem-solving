# O(sqrt(N))

from math import floor, ceil

N, K = map(int, input().split())

A, B = [], []
N1_2 = N ** (1 / 2)
for i in range(1, ceil(N1_2)):
	if N % i == 0:
		A.append(i); B.append(N // i)
if N == floor(N1_2) ** 2:
	A.append(N1_2)
B.reverse()
A += B

print(A[K - 1] if K - 1 < len(A) else 0)