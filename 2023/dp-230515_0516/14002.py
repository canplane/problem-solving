# naive O(N^2) : redirect to BOJ 14003 (O(NlgN))

import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())
A = list(map(int, input().split()))

prev = [ None ] * 1000

a = [ 0 ] * N
for i in range(N):
    for j in range(i)[::-1]:
        if A[j] < A[i]:
            a[i] = max(a[i], a[j])
    a[i] += 1

ans = 0; i = -1
for j in range(N):
    if a[j] > ans:
        ans = a[j]; i = j
seq = [ A[i] ]
for j in range(i)[::-1]:
    if a[j] + 1 == a[i] and A[j] < A[i]:
        seq.append(A[j])
        if a[j] == 0:   break
        i = j
print(ans)
print(*seq[::-1])