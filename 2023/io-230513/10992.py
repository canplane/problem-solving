N = int(input())
for i in range(N - 1):
    print(" " * ((N - 1) - i) + "*" + " " * (2 * i - 1) + "*" * bool(i))
print("*" * (2 * N - 1))