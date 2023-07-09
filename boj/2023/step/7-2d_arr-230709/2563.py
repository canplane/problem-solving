A = [ [0] * 100 for _ in range(100) ]

N = int(input())
for _ in range(N):
	x, y = map(int, input().split())
	for dy in range(10):
		for dx in range(10):
			A[y + dy][x + dx] = 1
ans = 0
for y in range(100):
	for x in range(100):
		ans += A[y][x] == 1
print(ans)