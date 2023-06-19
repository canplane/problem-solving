T = int(input())
for _ in range(T):
	s = input()
	ans = 0
	w = 0
	for c in s:
		if c == "O":
			w += 1
			ans += w
		else:
			w = 0
	print(ans)