N = int(input())

A = []
for i in range(N):
    A.append(input())

ord = 0
for i in range(N - 1):
    if A[i] < A[i + 1]:
        ord_t = -1
    elif A[i] > A[i + 1]:
        ord_t = 1
    if ord != 0 and ord_t != ord:
        print("NEITHER")
        exit()
    ord = ord_t
print("INCREASING" if ord == -1 else "DECREASING")    