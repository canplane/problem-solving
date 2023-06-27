A = [ int(input()) for _ in range(9) ]
k = sum(A)

def f():
	for i in range(9):
		for j in range(i + 1, 9):
			if k - A[i] - A[j] == 100:
				a, b = A[i], A[j]
				A.remove(a); A.remove(b)
				return
f()
A.sort()
print(*A, sep="\n")