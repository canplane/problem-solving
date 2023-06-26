# ceil(x / y)
def _ceil(x, y):
	return x // y + (x % y != 0)

A, B, V = map(int, input().split())
ans = _ceil(V - A, A - B) + 1
print(ans)