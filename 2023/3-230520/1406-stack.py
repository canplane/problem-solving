import sys
input = lambda: sys.stdin.readline().rstrip()
####

l = list(input()); r = list()
N = int(input())

for _ in range(N):
	cmd = input().split()
	if cmd[0] == "P":
		l.append(cmd[1])
	elif cmd[0] == "L":
		if len(l) > 0:
			r.append(l.pop())
	elif cmd[0] == "D":
		if len(r) > 0:
			l.append(r.pop())
	elif cmd[0] == "B":
		if len(l) > 0:
			l.pop()
print("".join(l + r[::-1]))