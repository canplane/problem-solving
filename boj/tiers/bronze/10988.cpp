#include <cstdio>

char s[101];
int f()
{
    int len;
    for (len = 0; s[len]; len++);
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - 1 - i])
            return 0;
    }
    return 1;
}

int main()
{
    scanf("%s", s);
    printf("%d", f());
}