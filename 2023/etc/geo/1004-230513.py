def has(cx, cy, r, x, y):
	return (x - cx) ** 2 + (y - cy) ** 2 < r ** 2

T = int(input())
for _ in range(T):
	x1, y1, x2, y2 = map(int, input().split())
	n = int(input())
	cnt = 0
	for _ in range(n):
		cx, cy, r = map(int, input().split())
		cnt += abs(has(cx, cy, r, x1, y1) - has(cx, cy, r, x2, y2))
	print(cnt)