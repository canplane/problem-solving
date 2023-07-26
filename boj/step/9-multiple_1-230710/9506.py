while True:
	N = int(input())
	if N == -1:
		break
	
	A, B = [], []
	for i in range(1, N + 1):
		if i * i >= N:
			if i * i == N:
				A.append(i)
			break
		if N % i == 0:
			A.append(i); B.append(N // i)
	A += B[::-1]
	A.pop()
	
	if sum(A) == N:
		print(f"{N} = {' + '.join(map(str, A))}")
	else:
		print(f"{N} is NOT perfect.")