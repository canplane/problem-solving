def f(c):
	if c >= 'Z':
		bias = 2
	elif c >= 'S':
		bias = 1
	else:
		bias = 0
	return 3 + (ord(c) - bias - 65) // 3

s = input()
ans = 0
for c in s:
	ans += f(c)
print(ans)