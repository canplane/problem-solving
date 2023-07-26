import sys
input = lambda: sys.stdin.readline().rstrip()

A, B, C, D = input().split()
A += B; C += D
print(int(A) + int(C))