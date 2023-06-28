# 수학적 사고력은 있어도 구현이 너무 오래 걸림

X = int(input())

lo = 0
n = 1
while True:
	if X <= lo + n:		# lo < X <= lo + n
		break
	lo += n
	n += 1

k = X - lo
a, b = k, (n + 1) - k
if n % 2 == 1:
	a, b = b, a

print(f"{a}/{b}")