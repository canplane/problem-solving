''' redirect to BOJ 12015 (on more data)
could be solved by DP due to its LESS DATA!!
	-> O(N^2) (naive)
using lower_bound() (BINARY SEARCH) is REQUIRED on more data
	-> O(NlgN) (-> BOJ 12015)
'''

import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())
A = list(map(int, input().split()))

a = [ 0 ] * N
for i in range(N):
	for j in range(i)[::-1]:
		if A[j] < A[i]:
			a[i] = max(a[i], a[j])
	a[i] += 1
print(max(a))