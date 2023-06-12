n, m = map(int, input().split())

def f(i, b):
	ret = 0
	while i > 0:
		ret += i // b
		i //= b
	return ret
ans = min(f(n, b) - f(m, b) - f(n - m, b) for b in [2, 5])
print(ans)