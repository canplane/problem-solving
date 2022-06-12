#include <cstdio>

int memo[1000][10] = { { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };

int main()
{
    int N, ans;
    scanf("%d", &N);
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k <= j; k++)
                memo[i][j] = (memo[i][j] + memo[i - 1][k]) % 10007;
        }
    }
    ans = 0;
    for (int j = 0; j < 10; j++)
        ans = (ans + memo[N - 1][j]) % 10007;
    printf("%d", ans);
}