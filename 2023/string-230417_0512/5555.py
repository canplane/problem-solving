key = input()
N = int(input())

ret = 0
for _ in range(N):
    if key in input() * 2:  ret += 1
print(ret)