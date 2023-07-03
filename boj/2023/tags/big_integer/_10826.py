# 파이썬은 큰 수 연산이 매우 쉽다.

f = [0] * 10001
f[0], f[1] = 0, 1
for i in range(2, 10001):
	f[i] = f[i - 1] + f[i - 2]

n = int(input())
print(f[n])