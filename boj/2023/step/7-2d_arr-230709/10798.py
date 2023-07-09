A = [ input() for _ in range(5) ]

for x in range(15):
    for y in range(5):
        if x < len(A[y]):
            print(A[y][x], end="")