# while은 for보다 느림 (그러나, pypy로는 돌아감)
# 이런 거 신경 안 쓰려면 그냥 C++이 나을 수도?

N = int(input())

dp = [0] * (1 + N)
for i in range(1, 1 + N):
	dp[i] = i
	x = 1
	while x * x <= i:
		dp[i] = min(dp[i], dp[i - x * x] + 1)
		x += 1
print(dp[N])