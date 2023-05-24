import sys
input = lambda: sys.stdin.readline().rstrip()

dp = [0] * 1000001
dp[0] = dp[1] = 1
for i in range(2, 500001):
	if dp[i] == 0:
		for j in range(2 * i, 1000001, i):
			dp[j] = 1

def f(n):
	for i in range(3, n - 2):
		if dp[i] == 0 and dp[n - i] == 0:
			return (i, n - i)

while True:
	n = int(input())
	if n == 0:	break
	print(f"{n} = {' + '.join(map(str, f(n)))}")