X = input()

d = {}
for i, c in enumerate(X[:-1]):
    if c not in d:
        d[c] = []
    d[c].append(i)
li = [ x[1] for x in sorted(list(d.items())) ][:2]
# print(li)

a = []
for e in li:
    a.extend(e)
a.sort()
# print(a)

def rev(i, j):
    return X[i::-1] + X[j:i:-1] + X[:j:-1]

ret = rev(a[0], a[1])
for i in range(0, len(a) - 1):
    for j in range(i + 1, len(a)):
        ret = min(ret, rev(a[i], a[j]))
print(ret)