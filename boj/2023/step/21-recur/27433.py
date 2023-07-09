def recur(n):
    if n == 0:
        return 1
    return n * recur(n - 1)
N = int(input())
print(recur(N))