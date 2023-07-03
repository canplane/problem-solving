from itertools import permutations

N = int(input())
perms = list(permutations(range(1, N + 1), N))
# perms.sort()
for perm in perms:
    print(*perm)