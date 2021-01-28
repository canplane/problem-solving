#include <cstdio>

int main()
{
    int N, i, j, d;
    scanf("%d", &N);
    for (i = 1, d = 1; i > 0; i += d) {  // d를 두는 것이 더 깔끔.
        for (j = 1; j <= i - 1; j++)
            printf(" ");
        for (j = 1; j <= 2 * (N - i) + 1; j++)
            printf("*");
        puts("");
        if (i == N) d = -1;
    }
}