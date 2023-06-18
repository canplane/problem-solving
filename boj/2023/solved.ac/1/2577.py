A = int(input())
B = int(input())
C = int(input())
ans = str(A * B * C)

for d in "0123456789":
    print(ans.count(d))