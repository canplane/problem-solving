N = int(input())
for i in list(range(1, N)) + list(range(N, 0, -1)):
	print(' ' * (N - i) + '*' * (2 * i - 1))