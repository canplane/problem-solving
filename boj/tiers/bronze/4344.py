import sys
input = lambda: sys.stdin.readline().rstrip()

C = int(input())
for _ in range(C):
    A = list(map(int, input().split()))
    mean = sum(A[1:]) / A[0]
    cnt = sum(a > mean for a in A[1:])
    print(f"{cnt * 100 / A[0]:.3f}%")