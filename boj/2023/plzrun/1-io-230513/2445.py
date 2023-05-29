N = int(input())
l = list(range(1, N + 1))
l += l[::-1][1:]
for i in l:
    s = "*" * i + " " * (N - i)
    s += s[::-1]
    print(s)