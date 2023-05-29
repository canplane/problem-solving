#include <cstdio>
#include <algorithm>

char s[1001], *post[1001];

bool cmp(const char *a, const char *b) {
    while (*a == *b && *a) a++, b++;
    return *a < *b;
}

int main()
{
    int i;
    scanf("%s", s);
    for (i = 0; s[i]; i++) post[i] = &s[i];
    std::sort(post, post + i, cmp);
    for (i = 0; post[i]; i++) printf("%s\n", post[i]);
}