import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())
A = [ list(map(int, input().split())) for _ in range(N) ]

def equal(ay, ax, d):
	k = A[ay][ax]
	for y in range(ay, ay + d):
		for x in range(ax, ax + d):
			if A[y][x] != k:
				return None
	return k

ans = [0, 0, 0]
def divcon(ay, ax, d):
	if (k := equal(ay, ax, d)) != None:
		ans[k + 1] += 1
	else:
		nd = d // 3
		for y in range(ay, ay + d, nd):
			for x in range(ax, ax + d, nd):
				divcon(y, x, nd)
divcon(0, 0, N)
print("\n".join(map(str, ans)))