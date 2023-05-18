# 이게 제일 빠름

import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())
A = [ list(map(int, input().split()))[::-1] for _ in range(N) ]
A.sort()

for a in A:
    print(*a[::-1])