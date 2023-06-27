# 수학적 사고력은 있어도 구현이 너무 오래 걸림

X = int(input())

g = 1
n = 0
while not X <= n + g:
	n += g
	g += 1

if g % 2 == 0:
	a = X - n
else:
	a = (g + 1) - (X - n)
print(f"{a}/{(g + 1) - a}")