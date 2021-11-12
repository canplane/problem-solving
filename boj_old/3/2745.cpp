#include <cstdio>

char s[32];

int main() {
    int w, ans = 0;
    scanf("%s %d", s, &w);
    for (int i = 0; s[i]; i++)
        ans = w * ans + s[i] - (s[i] > 64 ? 55 : 48);
    printf("%d", ans);
}