def gcd(a, b):
	while b:
		a, b = b, a % b
	return a

A, B, C, D = map(int, open(0).read().split())

n, d = A * D + B * C, B * D
g = gcd(n, d)
n //= g; d //= g
print(n, d)