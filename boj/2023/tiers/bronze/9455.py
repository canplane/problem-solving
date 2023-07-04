import sys
input = lambda: sys.stdin.readline().rstrip()

T = int(input())
for _ in range(T):
	m, n = map(int, input().split())
	A = [ list(map(int, input().split())) for _ in range(m) ]
	cnt = 0
	for x in range(n):
		k = m - 1
		for y in range(m)[::-1]:
			if A[y][x] == 1:
				cnt += k - y
				k -= 1
	print(cnt)