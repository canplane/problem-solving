memo = [ None ] * 41
memo[0] = (1, 0); memo[1] = (0, 1)
def f(n):
    if memo[n]: return memo[n]
    a, b = f(n - 1), f(n - 2)
    memo[n] = ( a[0] + b[0], a[1] + b[1] )
    return memo[n]

T = int(input())
for _ in range(T):
    print(*f(int(input())))