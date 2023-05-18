import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())
A = [ (int((t := input().split())[0]), t[1]) for _ in range(N) ]
A.sort(key=lambda x: x[0])
[ print(*a) for a in A ]