import sys
input = lambda: sys.stdin.readline().rstrip()

sys.setrecursionlimit(100000)

_d = [-1, 0, 1]
d = [ (dy, dx) for dy in _d for dx in _d ]
def dfs(y, x):
	A[y][x] = 0
	for dy, dx in d:
		ny = y + dy; nx = x + dx
		if 0 <= ny < h and 0 <= nx < w and A[ny][nx] == 1:
			dfs(ny, nx)
	
while True:
	w, h = map(int, input().split())
	if w == 0 and h == 0:
		break
	A = [ list(map(int, input().split())) for _ in range(h) ]
	ans = 0
	for y in range(h):
		for x in range(w):
			if A[y][x] == 1:
				dfs(y, x)
				ans += 1
	print(ans)