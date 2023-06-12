import sys
input = lambda: sys.stdin.readline().rstrip()


N = int(input())

a = [ None for _ in range(N + 1) ]
a[1] = [ 0, 1 ]
for i in range(2, N + 1):
    a[i] = [ a[i - 1][0] + a[i - 1][1], a[i - 1][0] ]
print(sum(a[N]))