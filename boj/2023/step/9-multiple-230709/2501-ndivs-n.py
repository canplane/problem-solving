# O(N)

N, K = map(int, input().split())

A = []
for i in range(1, N + 1):
	if N % i == 0:
		A.append(i)

print(A[K - 1] if K - 1 < len(A) else 0)