import sys
input = lambda: sys.stdin.readline().rstrip()

def dp():
	for i in range(2, N + 2):
		b0, b1 = (W >= A[0][i - 1] + A[0][i]), (W >= A[1][i - 1] + A[1][i])

		a0[i] = a1[i] = a[i - 1] + 1
		if b0:			a0[i] = min(a0[i], a1[i - 1] + 1)
		if b1:			a1[i] = min(a1[i], a0[i - 1] + 1)

		a[i] = min(a[i - 1] + (1 if W >= A[0][i] + A[1][i] else 2), a0[i] + 1, a1[i] + 1)
		if b0 and b1:	a[i] = min(a[i], a[i - 2] + 2)

T = int(input())
for _ in range(T):
	N, W = map(int, input().split())
	A = [ [ 0, 0 ] + list(map(int, input().split())) for _ in range(2) ]

	a, a0, a1 = [ [ 0 ] * (N + 2) for _ in range(3) ]

	dp()
	ans = a[-1]
	if N > 1:
		t, t0, t1 = W + 1, A[0][2], A[1][2]
		b0, b1 = (W >= A[0][2] + A[0][-1]), (W >= A[1][2] + A[1][-1])

		A[0][2] = A[1][2] = t; dp(); A[0][2], A[1][2] = t0, t1
		ans = min(ans, a[-2] + (0 if b0 and b1 else 2))

		A[0][2] = t; dp(); A[0][2] = t0
		ans = min(ans, a1[-1] + (0 if b0 else 1))

		A[1][2] = t; dp(); A[1][2] = t1
		ans = min(ans, a0[-1] + (0 if b1 else 1))
	print(ans)