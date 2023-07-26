from collections import deque

N, M = map(int, input().split())
A = list(map(int, input().split()))

ans = 0
q = deque(range(1, N + 1))
for a in A:
	i = q.index(a)
	if i > 0:
		if i <= len(q) - i:
			for i in range(i):
				ans += 1
				q.append(q.popleft())
		else:
			for i in range(len(q) - i):
				ans += 1
				q.appendleft(q.pop())
	q.popleft()
print(ans)