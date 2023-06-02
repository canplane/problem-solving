import sys
input = lambda: sys.stdin.readline().strip()
print = lambda *args, end="\n", sep=" ": sys.stdout.write(f"{sep.join(map(str, args))}{end}")


N = int(input())
A = [ [" "] * (2 * N - 1) for _ in range(N) ]

A3 = [
	"  *  ",
	" * * ",
	"*****",
]
def draw3(y, x):
	for dy in range(3):
		for dx in range(5):
			A[y + dy][x + dx] = A3[dy][dx]
def divide_and_conquer(y, x, h):
	if h == 3:
		draw3(y, x)
	else:
		h //= 2
		divide_and_conquer(y, x + h, h)
		divide_and_conquer(y + h, x, h)
		divide_and_conquer(y + h, x + 2 * h, h)

divide_and_conquer(0, 0, N)
print("\n".join([ "".join(Ay) for Ay in A ]))