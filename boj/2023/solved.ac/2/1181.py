N = int(input())

d = {}
for _ in range(N):
	k = input()
	if k not in d:
		d[k] = True
li = list(d.keys())
li.sort(key=lambda x: [len(x), x])	# functools.cmp_to_key()

print("\n".join(li))