import sys
input = lambda: sys.stdin.readline().rstrip()


N = int(input())
if N % 2:
	ans = 0
else:
	N //= 2
	S = a = 1
	for i in range(1, N + 1):
		a = a + 2 * S
		S += a
	ans = a
print(ans)