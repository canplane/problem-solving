from itertools import permutations

def next(s):
	permut = list(map("".join, list(permutations(s))))
	
	ret = None
	for p in permut:
		if p > s:
			ret = min(ret, p) if ret else p
	return ret if ret else s	

for _ in range(int(input())):
	s = input()
	print(next(s))