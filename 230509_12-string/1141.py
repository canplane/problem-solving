S = [ input() for _ in range(int(input())) ]
S.sort()

d = {}
for s in S:
	for k in d.keys():
		if s.startswith(k):	del d[k]; break
	d[s] = 1
print(len(d))