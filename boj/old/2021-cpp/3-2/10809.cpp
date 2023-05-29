#include <cstdio>
#include <cstring>

int a[26];

int main()
{
    int c, i = 0;
    memset(a, -1, sizeof(int) * 26);
    while ((c = getchar()) + 1) {
        if (!(a[c - 'a'] + 1)) a[c - 'a'] = i;
        i++;
    }
    for (i = 0; i < 26; i++) printf("%d ", a[i]);
}