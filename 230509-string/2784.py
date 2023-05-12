A = [ tuple(input()) for _ in range(6) ]

from itertools import permutations
permut = list(permutations(A))

res = 0
for p in permut:
	M = [ p[0], p[1], p[2] ]
	M_T = list(zip(*M))
	if [ p[3], p[4], p[5] ] == M_T:
		res = min(res, M, M_T) if res else min(M, M_T)
if res:
	for p in res:
		print("".join(p))
else:
	print(res)