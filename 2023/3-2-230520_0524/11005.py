# 2 <= base <= 36
ALPHA = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
def to_string(n, base=10):
	ret = []
	while n > 0:
		n, r = n // base, n % base
		ret.append(ALPHA[r])
	return "".join(ret[::-1])

N, B = map(int, input().split())
print(to_string(N, base=B))