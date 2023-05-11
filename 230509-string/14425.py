N, M = map(int, input().split())

d = { input() for _ in range(N) }
res = [ input() in d for _ in range(M) ]
print(sum(res))