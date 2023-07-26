import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda *x: sys.stdout.write(f"{' '.join(map(str, x))}\n")

N = int(input())

li = []
def dc(n, i, j, t):
	if n == 0:	return 0
	dc(n - 1, i, t, j)
	li.append([i, j])
	dc(n - 1, t, j, i)
dc(N, 1, 3, 2)
print(len(li))
print("\n".join([ " ".join(map(str, e)) for e in li ]))