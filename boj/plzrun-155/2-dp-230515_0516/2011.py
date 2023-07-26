import sys
input = lambda: sys.stdin.readline().rstrip()

s = input()
n = len(s)

def sol():
	dp = [ 0 ] * (n + 1)
	dp[-1] = 1
	for i in range(n):
		b = False
		if True:
			x = int(s[i])
			if 1 <= x <= 9:
				dp[i] = (dp[i] + dp[i - 1]) % 1000000; b |= True
		if i > 0:
			x = int(s[(i - 1):(i + 1)])
			if 10 <= x <= 26:
				dp[i] = (dp[i] + dp[i - 2]) % 1000000; b |= True
		if not b:
			return 0
	return dp[n - 1]
print(sol())