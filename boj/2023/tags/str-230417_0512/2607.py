N = int(input())

def D():
    d = {}
    for c in input():
        if c not in d:
            d[c] = 0
        d[c] += 1
    return d

cnt = 0

AA = D()
for _ in range(N - 1):
    A = AA.copy()
    B = D()
    
    for k in B:
        if k not in A:
            A[k] = 0
        A[k] -= B[k]
    
    pos = 0; neg = 0
    for k in A:
        if A[k] >= 0:
            pos += abs(A[k])
        else:
            neg += abs(A[k])

    if pos + neg <= 1:
        cnt += 1
    elif pos == 1 and neg == 1:
        cnt += 1

print(cnt)