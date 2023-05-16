import sys
input = lambda: sys.stdin.readline().rstrip()


N, K = list(map(int, input().split()))
dp = [ [0] * (N + 1) for _ in range(K + 1) ]

for j in range(0, N + 1):
    dp[1][j] = 1
for i in range(2, K + 1):
    dp[i][0] = dp[i - 1][0]
    for j in range(1, N + 1):
        dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 1_000_000_000
print(dp[K][N])

'''
for dp1 in dp:
    for dp2 in dp1:
        print(f"{dp2:3d}", end=" ")
    print()
'''