N = int(input())

ans = 0
for i in range(N + 1):
	x = i + sum(list(map(int, str(i))))
	if x == N:
		ans = i
		break
print(ans)