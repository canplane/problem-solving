import sys
input = lambda: sys.stdin.readline().rstrip()

from collections import deque

deq = deque()

N = int(input())
for _ in range(N):
	s = input().split()
	if s[0] == "push_back":
		x = int(s[1])
		deq.append(x)
	if s[0] == "push_front":
		x = int(s[1])
		deq.appendleft(x)
	elif s[0] == "pop_front":
		x = deq.popleft() if len(deq) else -1
		print(x)
	elif s[0] == "pop_back":
		x = deq.pop() if len(deq) else -1
		print(x)
	elif s[0] == "front":
		x = deq[0] if len(deq) else -1
		print(x)
	elif s[0] == "back":
		x = deq[-1] if len(deq) else -1
		print(x)
	elif s[0] == "size":
		print(len(deq))
	elif s[0] == "empty":
		print(int(not len(deq)))
