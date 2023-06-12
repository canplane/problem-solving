from math import gcd

t = int(input())
for _ in range(t):
	_, *A = map(int, input().split())
	ans = 0
	for i in range(len(A)):
		for j in range(i + 1, len(A)):
			ans += gcd(A[i], A[j])
	print(ans)