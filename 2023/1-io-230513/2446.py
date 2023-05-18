N = int(input())
l = list(range(N))
for i in l + l[::-1][1:]:
    print(" " * i + "*" * (2 * (N - i) - 1))