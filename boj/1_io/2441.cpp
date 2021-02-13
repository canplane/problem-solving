#include <cstdio>

int main()
{
    int n, i, j;
    scanf("%d", &n);
    for (i = n; i > 0; i--) {
        for (j = 0; j < n - i; j++)
            putchar(' ');
        for (j = 0; j < i; j++)
            putchar('*');
        putchar('\n');
    }
}