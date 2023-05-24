import sys
input = lambda: sys.stdin.readline().rstrip()

A, B = map(int, input().split())
def gcd(a, b):
	while b:	a, b = b, a % b
	return a
print("1" * gcd(A, B))