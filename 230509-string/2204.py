import sys
input = lambda: sys.stdin.readline().rstrip()

while (N := int(input())) != 0: 
    A = []
    for i in range(N):
        s = input()
        A.append([s.lower(), s])
    A.sort()
    print(A[0][1])        
