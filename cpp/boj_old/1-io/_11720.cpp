#include <cstdio>

int main()
{
    int n, x, sum = 0;
    scanf("%d%*c", &n);
    while (n--)
        scanf("%1d", &x), sum += x;  // 최대 1자리만
    printf("%d", sum);
}