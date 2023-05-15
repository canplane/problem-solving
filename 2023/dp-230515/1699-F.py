# while은 for보다 느림 (그러나, pypy로는 돌아감)
# 이런 거 신경 안 쓰려면 그냥 C++이 나을 수도?

N = int(input())

dp = [0] * (N + 1)
for i in range(1, N + 1):
	dp[i] = i; j = 1
	while (tmp := i - j ** 2) >= 0:
		dp[i] = min(dp[i], 1 + dp[tmp]); j += 1
print(dp[N])

d+=[1+min(d[i-j*j]for j in range(1,int(i**.5)+1))]