import sys
for s in sys.stdin.readlines():
	print(sum(map(int, s.split())))