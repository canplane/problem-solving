'''
brute: (M+N) * MN  ~N^3
-> DP
'''

def f(A, R, C):
	ret = "z" * (R + C)
	for y in range(R):
		i = 0
		while i < C:
			j = i
			while j < C and A[y][j] != "#":
				j += 1
			if j - i >= 2:
				ret = min(ret, "".join(A[y][i:j]))
			i = j + 1
	return ret

R, C = map(int, input().split())
A = [ tuple(input()) for _ in range(R) ]
A_T = list(zip(*A))		# [ [ A[y][x] for y in range(R) ] for x in range(C) ]
print(min(f(A, R, C), f(A_T, C, R)))