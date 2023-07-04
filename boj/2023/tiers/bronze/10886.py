import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())
A = [ int(input()) for _ in range(N) ]
print(f"Junhee is {'' if int(sum(A) / N + 0.5) else 'not '}cute!")