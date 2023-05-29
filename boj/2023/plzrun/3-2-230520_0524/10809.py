s = input()

li = [-1] * 26
for i, c in enumerate(s):
	j = ord(c) - 97
	if li[j] == -1:
		li[j] = i
for e in li:
	print(f"{e} ", end="")