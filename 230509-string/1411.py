def f(s):
	t = []
	d = {}; j = 0
	for c in s:
		if c not in d:
			d[c] = j
			j += 1
		t.append(str(d[c]))
	return "".join(t)

d = {}
for s in [ f(input()) for _ in range(int(input())) ]:
	if s not in d:  d[s] = 0
	d[s] += 1
print(sum([ n * (n - 1) // 2 for n in d.values() ]))