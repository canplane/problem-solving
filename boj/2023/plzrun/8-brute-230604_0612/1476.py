E, S, M = map(int, input().split())

while E != S:
	if E < S:
		E += 15
	else:
		S += 28

from math import lcm
while S != M:
	if S < M:
		S += lcm(15, 28)
	else:
		M += 19
print(M)