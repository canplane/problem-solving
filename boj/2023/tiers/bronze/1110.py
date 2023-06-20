N = int(input())

i = N; ans = 0
while True:
    i = i % 10 * 10 + sum(map(int, str(i))) % 10
    ans += 1
    if i == N:
        break
print(ans)