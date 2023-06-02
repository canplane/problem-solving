import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *x: sys.stdout.write(f"{' '.join(map(str, x))}\n")

N = int(input())

li = []
def divcon(n, i, j, t):
	if n == 0:	return 0
	divcon(n - 1, i, t, j)
	li.append([i, j])
	divcon(n - 1, t, j, i)
divcon(N, 1, 3, 2)
print(len(li))
print("\n".join([ " ".join(map(str, e)) for e in li ]))