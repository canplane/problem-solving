import sys
input = lambda: sys.stdin.readline().rstrip()

from collections import deque

dy = [-2, -2, -1, -1, 1, 1, 2, 2]
dx = [-1, 1, -2, 2, -2, 2, -1, 1]
def bfs(y0, x0, y1, x1):
	global dy, dx, l

	visit = [ [ False for _ in range(l) ] for _ in range(l) ]
	q = deque()
	visit[y0][x0] = True; q.append([y0, x0, 0])
	while len(q) > 0:
		y, x, d = q.popleft()
		if [y, x] == [y1, x1]:
			return d
		for i in range(8):
			ny, nx = y + dy[i], x + dx[i]
			if not (0 <= ny < l and 0 <= nx < l):
				continue
			if visit[ny][nx]:
				continue
			visit[ny][nx] = True; q.append([ny, nx, d + 1])
	return -1

T = int(input())
for _ in range(T):
	l = int(input())
	y0, x0 = map(int, input().split())
	y1, x1 = map(int, input().split())
	print(bfs(y0, x0, y1, x1))