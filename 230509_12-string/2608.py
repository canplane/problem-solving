A, B = input(), input()

F = { "I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000 }
def f(S):
	li = []
	for C in S:
		c = F[C]
		n = 0
		while len(li) and li[-1] < c:
			n += li.pop()
		li.append(-n + c)
	return sum(li)

def G(w, q):
	i, v, x = "IXCM"[w], "VLD_"[w], "XCM_"[w]
	return [ "", i, i * 2, i * 3, i + v, v, v + i, v + (i * 2), v + (i * 3), i + x ][q]
def g(n):
	return G(3, (n // 1000) % 10) + G(2, (n // 100) % 10) + G(1, (n // 10) % 10) + G(0, n % 10)

a, b = f(A), f(B)
c = a + b
print(c, g(c))