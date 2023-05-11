s = input()
l0 = s.count("0"); l1 = len(s) - l0
l0 //= 2; l1 //= 2

t = [ None ] * (l0 + l1)
i, j = 0, 0
while i < len(s):
	if s[i] == "0":
		if l0:
			t[j] = s[i]; j += 1
			l0 -= 1
	else:
		if l1:
			l1 -= 1
		else:
			t[j] = s[i]; j += 1
	i += 1
print("".join(t))