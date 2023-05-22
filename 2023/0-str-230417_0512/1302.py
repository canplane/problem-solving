d = {}
for _ in range(int(input())):
	k = input()
	if k not in d:  d[k] = 0
	d[k] += 1

K, V = None, -1
for k in d:
	if d[k] > V or (d[k] == V and k < K):
		K, V = k, d[k]
print(K)