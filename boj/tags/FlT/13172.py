P = 1000000007
def po(x, n):
	if n == 0:
		return 1
	return ((po(x, n // 2) ** 2) * (x if n % 2 else 1)) % P
def cong(nu, de):
	return (nu * po(de, P - 2)) % P

N = int(input())
ans = 0
for i in range(N):
	n, s = map(int, input().split())
	ans = (ans + cong(s, n)) % P
print(ans)