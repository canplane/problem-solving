T = int(input())
for _ in range(T):
    print(*[ s[::-1] for s in input().split() ])