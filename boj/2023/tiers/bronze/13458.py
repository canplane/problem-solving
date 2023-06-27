import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())
A = list(map(int, input().split()))
B, C = map(int, input().split())

ans = 0
for i in range(N):
	a = A[i] - B
	ans += 1
	if a >= 0:
		ans += a // C + (a % C > 0)
print(ans)