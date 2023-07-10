a1, a0 = map(int, input().split())
c, n0 = int(input()), int(input())

if c - a1 > 0:
    ans = (c - a1) * n0 >= a0
elif c - a1 == 0:
    ans = a0 <= 0
else:
    ans = 0
print(int(ans))