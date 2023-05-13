#include <cstdio>

int cost(char s[])
{
    int inv = 0;
    int bias = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '}')
            bias--;
        else if (s[i] == '{')
            bias++;
        
        if (bias == -1) {
            bias = 1;
            inv++;
        }
    }
    return inv + bias / 2;
}

char s[2001];

int main()
{
    for (int i = 1; ; i++) {
        scanf("%s", s);
        if (s[0] == '-')
            break;
        printf("%d. %d\n", i, cost(s));
    }
}