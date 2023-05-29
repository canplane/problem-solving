from itertools import permutations

X = input()     # '21'
x = int(X)

permute = permutations(list(X))
permute = [ int("".join(x)) for x in list(permute) ]     # [21, 12]

res = -1
for e in permute:
    if e <= x:
        continue
    if res == -1 or e < res:
        res = e
print(0 if (res == -1) else res)