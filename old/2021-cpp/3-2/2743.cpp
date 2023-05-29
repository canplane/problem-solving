#include <cstdio>

int main()
{
    int c, i = 0;
    while ((c = getchar()) != '\n' && c + 1) i++;
    printf("%d", i);
}