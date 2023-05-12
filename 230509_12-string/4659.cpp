#include <cstdio>
#include <cstring>

void tc(char *s)
{
    int aeiou = 0;
    int bias = 0;
    int is_err = 0;

    char c, c_prev;
    for (int i = 0; (c = s[i]); i++) {
        switch (c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                aeiou = 1;
                if (bias > 0)   bias = 0;
                bias -= 1;
                break;
            default:
                if (bias < 0)   bias = 0;
                bias += 1;
                break;
        }
        if (bias <= -3 || bias >= 3)
            is_err = 1;
        if (c_prev == c && c_prev != 'e' && c_prev != 'o')
            is_err = 1;
        c_prev = c;

        if (is_err)
            break;
    }
    if (!aeiou)
        is_err = 1;

    printf("<%s> is %sacceptable.\n", s, is_err ? "not " : "");
}
int main()
{
    char s[21];
    while (1) {
        scanf("%s", s);
        if (!strcmp(s, "end"))
            break;
        tc(s);
    }
}