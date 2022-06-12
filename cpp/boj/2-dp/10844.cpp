#include <cstdio>

int dp[100][10] = { { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };

int main()
{
    int N, sum;
    for (int i = 1; i < 100; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0)
                dp[i][j] = dp[i - 1][j + 1];
            else if (j == 9)
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
        }
    }

    scanf("%d", &N);
    sum = 0;
    for (int j = 0; j < 10; j++)
        sum = (sum + dp[N - 1][j]) % 1000000000;  // 나머지 안 써서 틀림 ㅡㅡ
    printf("%d", sum);
}