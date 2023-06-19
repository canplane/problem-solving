T = int(input())
for _ in range(T):
    R, S = input().split()
    R = int(R)
    for c in S:
        print(c * R, end="")
    print()