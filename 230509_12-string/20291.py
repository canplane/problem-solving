N = int(input())

li = []; d = {}
for _ in range(N):
    ext = input().split(".")[-1]
    if ext not in d: d[ext] = 0
    d[ext] += 1
for k, e in sorted(d.items()):
    print(f"{k} {e}")