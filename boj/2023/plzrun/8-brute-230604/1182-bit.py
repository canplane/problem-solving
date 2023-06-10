import sys
input = lambda: sys.stdin.readline().rstrip()

N, S = map(int, input().split())
A = list(map(int, input().split()))

cnt = 0
for x in range(1, 2 ** N):
	li = []
	for i in range(N):
		if x & (1 << i):
			li.append(A[i])
	if sum(li) == S:
		cnt += 1
print(cnt)