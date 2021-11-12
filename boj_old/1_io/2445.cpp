#include <cstdio>

int main()
{
    int n, i, j;
    bool b = true;

    scanf("%d", &n);
    for (i = 1; i <= n; b ? i++ : i--) {
        for (j = 1; j <= i; j++)
            putchar('*');
        for (j = 1; j <= 2 * (n - i); j++)
            putchar(' ');
        for (j = 1; j <= i; j++)
            putchar('*');
        putchar('\n');
        if (b) {
            if (i == n) b = !b;
        } else if (!i)
            break;
    }
}