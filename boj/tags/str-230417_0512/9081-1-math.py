"""
7/8\0/4\3\2
78[2]|430
78[2]|034
78[2]|0[3]4
78[3]|0[2]4
783024
"""
def next(s):
	s = list(s)

	asc = -1
	for i in range(len(s) - 1):
		if s[i] < s[i + 1]:
			asc = i
	if asc != -1:
		l = s[:asc]
		m = s[asc]
		r = sorted(s[(asc + 1):])
		for i in range(len(r)):
			if m < r[i]:
				m, r[i] = r[i], m
				break
		s = l + [m] + r
	return "".join(s)

for _ in range(int(input())):
	s = input()
	print(next(s))