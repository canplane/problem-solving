#include <cstdio>

char s[51], *p;

int main()
{
    int T, d;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        for (p = s, d = 0; *p && d >= 0; p++) {  // d >= 0 주의!
            if (*p == '(') ++d;
            else --d;
        }
        printf("%s\n", d ? "NO" : "YES");
    }
}