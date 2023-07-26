N = int(input())

# bin(N)[2:]
ans = ""
while N > 0:
    ans += str(N % 2)
    N //= 2
print(ans[::-1])