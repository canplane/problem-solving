import sys
input = lambda: sys.stdin.readline().rstrip()

from collections import deque

queue = deque()

N = int(input())
for _ in range(N):
	s = input().split()
	if s[0] == "push":
		x = int(s[1])
		queue.append(x)
	elif s[0] == "pop":
		x = queue.popleft() if len(queue) else -1
		print(x)
	elif s[0] == "front":
		x = queue[0] if len(queue) else -1
		print(x)
	elif s[0] == "back":
		x = queue[-1] if len(queue) else -1
		print(x)
	elif s[0] == "size":
		print(len(queue))
	elif s[0] == "empty":
		print(int(not len(queue)))
