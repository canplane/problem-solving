A = [ list(map(int, input().split())) for _ in range(9) ]

ans = A[y0 := 0][x0 := 0]
for y in range(9):
    for x in range(9):
        if A[y][x] > ans:
            ans = A[y0 := y][x0 := x]
print(ans, y0 + 1, x0 + 1) 