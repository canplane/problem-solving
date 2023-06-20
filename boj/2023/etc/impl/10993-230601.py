import sys
input = lambda: sys.stdin.readline().strip()
print = lambda *args, end="\n", sep=" ": sys.stdout.write(f"{sep.join(map(str, args))}{end}")


N = int(input())
A = [ [" "] * (2 ** (N + 1) - 3) for _ in range(2 ** N - 1) ]

def slash(y, x, h):
	for dy in range(h):
		A[y + dy][(x + h - 1) - dy] = "*"
def backslash(y, x, h):
	for dy in range(h):
		A[y + dy][x + dy] = "*"
def dash(y, x, w):
	for dx in range(w):
		A[y][x + dx] = "*"
def recur(y, x, n):
	if n == 1:
		A[y][x] = "*"
		return
	
	h = 2 ** (n - 1) - 1
	if n % 2 == 1:
		slash(y, x + 1, 2 * h); backslash(y, x + 2 * h, 2 * h)
		recur(y + h, x + h + 1, n - 1)
		dash(y + 2 * h, x, 4 * h + 1)
	else:
		dash(y, x, 4 * h + 1)
		recur(y + 1, x + h + 1, n - 1)
		backslash(y + 1, x + 1, 2 * h); slash(y + 1, x + 2 * h,  2 * h)

recur(0, 0, N)
print("\n".join([ "".join(Ay).rstrip() for Ay in A ]))