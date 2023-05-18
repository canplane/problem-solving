# 이게 제일 느림

import sys
input = lambda: sys.stdin.readline().rstrip()

from functools import cmp_to_key

def cmp(a, b):
    return (a[1] - b[1]) if (a[1] - b[1] != 0) else (a[0] - b[0])

N = int(input())
A = [ list(map(int, input().split())) for _ in range(N) ]
A.sort(key=cmp_to_key(cmp))

for a in A:
    print(*a)