#include <cstdio>
#define MAX_N 1000

int dp[MAX_N + 1] = { -1, 1, 3 };

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 3; i <= n; i++)
        dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
    printf("%d", dp[n]);
}