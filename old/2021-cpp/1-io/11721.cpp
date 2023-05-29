#include <cstdio>

int main()
{
    char c;
    int i = 0;
    while ((c = getchar()) + 1) {
        putchar(c);
        if (!(i = (i + 1) % 10))
            putchar('\n');
    }
}