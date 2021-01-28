#include <cstdio>

int main()
{
    int n, s = 0;
    scanf("%d", &n);
    while (n)
        s += n--;
    printf("%d\n", s);
}