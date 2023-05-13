a = set()
b = set()

N, M = map(int, input().split())
for _ in range(N):
    a.add(input())
for _ in range(M):
    b.add(input())
print(len(a & b))
for e in sorted(list(a & b)):
    print(e)