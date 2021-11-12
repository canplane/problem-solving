#include <cstdio>

int main()
{
    int n, i, j;
    bool b = true;
    scanf("%d", &n);
    for (i = 1; i >= 1; b ? i++ : i--) {
        for (j = 1; j <= n - i; j++)
            putchar(' ');
        for (j = 1; j <= i; j++)
            putchar('*');
        putchar('\n');
        if (i == n) b = !b;
    }
}