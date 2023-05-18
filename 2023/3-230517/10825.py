import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())
A = [ (-int((t := input().split())[1]), int(t[2]), -int(t[3]), t[0]) for _ in range(N) ]
A.sort()
[ print(a[3]) for a in A ]