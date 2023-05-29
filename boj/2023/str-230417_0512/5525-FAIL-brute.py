N = int(input())
P = "IO" * N + "I"

M = int(input())
S = input()

res = 0
pos = -1
while True:
    pos = S.find(P, pos + 1)
    if pos == -1:
        break
    res += 1
print(res)