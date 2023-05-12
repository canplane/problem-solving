T = int(input())
for _ in range(T):
	N = int(input())
	s1 = input().split()
	s2 = input().split()

	d = {}
	for i, e in enumerate(s1):
		d[e] = i
	f_inv = [ None ] * N
	for i, e in enumerate(s2):
		f_inv[i] = d[e]
	#print(f_inv)

	res = [ None ] * N
	s3 = input().split()
	for i, e in enumerate(s3):
		res[f_inv[i]] = e
	print(" ".join(res))