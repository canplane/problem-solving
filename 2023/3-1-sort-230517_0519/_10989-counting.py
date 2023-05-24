import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())
A = [0] * 10001
for i in range(N):
    A[int(input())] += 1
for i in range(1, 10001):
    for _ in range(A[i]):
        print(i)