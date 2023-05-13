N = int(input())
l = list(range(1, N + 1))
l += l[::-1][1:]
for i in l:
    print(" " * (N - i) + "*" * i)