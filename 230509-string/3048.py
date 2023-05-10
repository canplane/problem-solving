N1, N2 = map(int, input().split())
A = input()[::-1]
B = input()
T = int(input())

sA = ""
for c in A: sA += " " + c
sB = " " * len(sA)
for c in B: sB += c + " "
sA = "  " * T + sA
#print(sB)
#print(sA)

if len(sA) < len(sB):
    sA += " " * (len(sB) - len(sA))
else:
    sB += " " * (len(sA) - len(sB))

s = ""
for i in range(len(sB)):
    if sA[i] != " ":
        s += sA[i]
    elif sB[i] != " ":
        s += sB[i]
print(s)
