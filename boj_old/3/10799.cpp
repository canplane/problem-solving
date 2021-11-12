#include <cstdio>

char s[100001];

int main()
{
    int i, dep = 0, ans = 0;
    scanf("%s", s);
    for (i = 0; s[i]; i++) {
        if (s[i] == '(') {
            if (s[i + 1] == ')') {
                ans += dep;
                i++;
            } else {
                dep++;
            }
        } else {
            dep--, ans++;
        }
    }
    printf("%d", ans);
}