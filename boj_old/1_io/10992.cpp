#include <cstdio>

int main()
{
    int N, i, j;
    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        for (j = 0; j < N + i; j++) {
            if (j == (N - 1) - i || j == (N - 1) + i)
                printf("*");
            else if (i == N - 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}