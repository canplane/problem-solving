X = input()

asc = -1
for i in range(len(X) - 1):
    if X[i] < X[i + 1]:
        asc = i

if asc == -1:
    print(0)
else:
    X = list(X)
    X = X[:(asc + 1)] + sorted(X[(asc + 1):])
    for i in range(asc + 1, len(X)):
        if X[asc] < X[i]:
            X[asc], X[i] = X[i], X[asc]
            break
    X = "".join(X)
    print(X)
