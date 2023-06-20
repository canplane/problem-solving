while True:
	A = list(map(int, input().split()))
	if A[0] == 0:
		break
	A.sort()
	print("right" if A[0] ** 2 + A[1] ** 2 == A[2] ** 2 else "wrong")