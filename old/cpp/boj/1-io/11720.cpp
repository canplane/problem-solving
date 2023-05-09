#include <cstdio>

int main()
{
    int n, sum = 0;
    scanf("%d", &n), getchar();
    while (n--)
        sum += getchar() - '0';
    printf("%d", sum);
}