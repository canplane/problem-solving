from itertools import combinations

X = input()
combs = list(combinations(range(0, len(X) - 1), 2))

res = -1
for i, j in combs:
    tmp = X[i::-1] + X[j:i:-1] + X[:j:-1]
    if res == -1 or tmp < res:
        res = tmp
print(res)