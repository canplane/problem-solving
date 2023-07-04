import sys
input = lambda: sys.stdin.readline().rstrip()

from collections import deque
q = deque()

N = int(input())
for _ in range(N):
	s = input().split()
	f, b = [q[0], q[-1]] if len(q) else [-1, -1]
	match s[0]:
		case "push": q.append(s[1])
		case "pop": print(q.popleft() if len(q) else -1)
		case "size": print(len(q))
		case "empty": print(+(not len(q)))
		case "front": print(f)
		case "back": print(b)