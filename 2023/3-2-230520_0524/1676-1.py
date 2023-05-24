N = int(input())

ans = 0
t = 1
for i in range(1, N + 1):
	if i % 2 == 0 or i % 5 == 0:
		t *= i
	while t % 10 == 0:
		t //= 10; ans += 1
print(ans)