s = input()
l = len(s)

res = "z" * l
for i in range(1, l - 1):
	for j in range(i + 1, l):
		res = min(res, s[:i][::-1] + s[i:j][::-1] + s[j:][::-1])
print(res)