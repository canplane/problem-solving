import sys
input = lambda: sys.stdin.readline().rstrip()

from collections import deque

def parse():
	global x, xs
	xs = xs[1:-1]
	if len(xs) > 0:	
		for d in xs.split(","):
			x.append(d)
def solve():
	global x, p
	rc = 0
	for c in p:
		if c == "D":
			if len(x) > 0:
				if rc % 2:
					x.pop()
				else:
					x.popleft()
			else:
				print("error")
				return
		else:
			rc += 1
	if rc % 2:
		x.reverse()
	print(f"[{','.join(x)}]")

T = int(input())
for _ in range(T):
	p = input()
	n = int(input())
	xs = input()
	x = deque()
	parse()
	solve()