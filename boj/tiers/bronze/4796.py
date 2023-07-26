i = 0
while True:
	L, P, V = map(int, input().split())
	if L == 0:
		break
	i += 1
	ans = V // P * L + min(V - V // P * P, L)
	print(f"Case {i}: {ans}")