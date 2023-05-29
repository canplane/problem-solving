import sys
input = lambda: sys.stdin.readline().rstrip()


N = int(input())
A = [ int(input()) for _ in range(N) ]
A.sort()
print("\n".join([ str(x) for x in A ]))