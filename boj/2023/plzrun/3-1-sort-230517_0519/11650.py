import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())
A = [ tuple(map(int, input().split())) for _ in range(N) ]
A.sort()

for a in A:
    print(*a)