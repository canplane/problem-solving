import sys
input = lambda: sys.stdin.readline().rstrip()

N, M = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = [0] * (len(A) + len(B))

i = j = k = 0
while i < len(A) and j < len(B):
	if A[i] <= B[j]:
		C[k] = A[i]; i += 1
	else:
		C[k] = B[j]; j += 1
	k += 1
while i < len(A):
	C[k] = A[i]; i += 1
	k += 1
while j < len(B):
	C[k] = B[j]; j += 1
	k += 1
print(" ".join(map(str, C)))