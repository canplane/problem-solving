import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())
for _ in range(N):
    c, v = map(int, input().split())
    print(f"You get {c // v} piece(s) and your dad gets {c % v} piece(s).")