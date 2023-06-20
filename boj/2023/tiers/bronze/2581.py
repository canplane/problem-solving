np = [0] * 10001
def eratos():
	global np
	np[0] = np[1] = 1
	for i in range(2, 5001):
		if np[i] == 1:
			continue
		for j in range(2 * i, 10001, i):
			np[j] = 1
eratos()

M = int(input())
N = int(input())

s, m = 0, -1
for i in range(M, N + 1):
	if np[i] == 0:
		s += i
		if m == -1:
			m = i
if m == -1:
	print(-1)
else:
	print(s)
	print(m)