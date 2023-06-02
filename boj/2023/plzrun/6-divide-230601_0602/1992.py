import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())
A = [ list(map(int, input())) for _ in range(N) ]

def equal(ay, ax, d):
	a = A[ay][ax]
	for y in range(ay, ay + d):
		for x in range(ax, ax + d):
			if A[y][x] != a:
				return None
	return a

def divcon(ay, ax, d):
	if (k := equal(ay, ax, d)) != None:
		return str(k)
	else:
		ret = "("
		nd = d // 2
		for y in range(ay, ay + d, nd):
			for x in range(ax, ax + d, nd):
				ret += divcon(y, x, nd)
		ret += ")"
		return ret

print(divcon(0, 0, N))