L = int(input())
s = reversed(input())
ans = 0
for c in s:
    ans = 31 * ans + (ord(c) - 96)
ans %= 1234567891
print(ans)