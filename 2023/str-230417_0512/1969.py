N, M = list(map(int, input().split()))

C = { 'A': 0, 'C': 0, 'G': 0, 'T': 0 }
cnt = [ C.copy() for _ in range(M) ]
for _ in range(N):
    for i, c in enumerate(input()):
        cnt[i][c] += 1

res = ""
dist = 0
for i in range(M):
    max_c = max(cnt[i], key=cnt[i].get)
    res += max_c
    for c in cnt[i]:
        if c != max_c:
            dist += cnt[i][c]
print(res)
print(dist) 