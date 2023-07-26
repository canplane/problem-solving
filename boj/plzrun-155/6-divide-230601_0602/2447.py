import sys
print = lambda *x: sys.stdout.write(f"{' '.join(map(str, x))}\n")


N = int(input())
A = [ [" "] * N for _ in range(N) ]

def dc(ay, ax, d):
	if d == 1:
		A[ay][ax] = "*"
	else:
		nd = d // 3
		for y in range(ay, ay + d, nd):
			for x in range(ax, ax + d, nd):
				if y == ay + nd and x == ax + nd:
					continue
				dc(y, x, nd)
dc(0, 0, N)
print("\n".join([ "".join(map(str, A[y])) for y in range(N) ]))