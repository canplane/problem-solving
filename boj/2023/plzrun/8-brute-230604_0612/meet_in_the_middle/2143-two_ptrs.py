import sys
input = lambda: sys.stdin.readline().rstrip()

def f(a):
	s, n = [], len(a)
	s.append(0)
	for i in range(n):
		s.append(s[-1] + a[i])
	ret = []
	for i in range(n + 1):
		for j in range(i + 1, n + 1):
			ret.append(s[j] - s[i])
	ret.sort()
	return ret

T = int(input())
n, A = int(input()), list(map(int, input().split()))
m, B = int(input()), list(map(int, input().split()))
fA, fB = f(A), f(B)

cnt = 0
i, j = 0, len(fB) - 1
while i < len(fA) and j >= 0:
	if fA[i] + fB[j] == T:
		i_l, j_r = i, j
		while i < len(fA) and fA[i] == fA[i_l]:
			i += 1
		while j >= 0 and fB[j] == fB[j_r]:
			j -= 1
		cnt += (i - i_l) * (j_r - j)
	else:
		if fA[i] + fB[j] < T:
			i += 1
		else:
			j -= 1
print(cnt)