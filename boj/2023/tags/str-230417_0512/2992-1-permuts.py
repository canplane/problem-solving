from itertools import permutations

X = input()     # '21'
x = int(X)

perms = permutations(list(X))
perms = [ int("".join(x)) for x in list(perms) ]     # [21, 12]

res = -1
for e in perms:
    if e <= x:
        continue
    if res == -1 or e < res:
        res = e
print(0 if (res == -1) else res)