# summuus
# suummus
def check(s):
	t = s[::-1]
	for i in range(len(s)):
		if s[i] != t[i]:
			s = s[:i] + s[(i + 1):]
			t = t[:i] + t[(i + 1):]
			return s == s[::-1] or t == t[::-1]
	return 2

for _ in range(int(input())):
	print(2 - check(input()))