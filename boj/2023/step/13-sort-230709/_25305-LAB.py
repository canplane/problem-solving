from random import random

def nth_element(l, r, nth):
	global A
	if l == r: return

	piv = A[l + int((r - l) * random())]
	i, j = l - 1, r
	while True:
		while A[i := i + 1] < piv:  pass
		while A[j := j - 1] > piv:  pass
		if i >= j:	break
		A[i], A[j] = A[j], A[i]
	
	if nth < i:
		nth_element(l, i, nth)
	else:
		nth_element(j + 1, r, nth)

N, k = map(int, input().split())
A = list(map(int, input().split()))
nth_element(0, N, N - k)
print(A[N - k])