import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())
A = list(map(int, input().split()))

from bisect import bisect_left

# O(NlgN): not naive
LIS = []
for i in range(N)[::-1]:
    l = bisect_left(LIS, A[i])
    if l == len(LIS):
        LIS.append(0)
    LIS[l] = A[i]

print(len(LIS))