#include <cstdio>
int a[26], i;
int main() {
    while ((i = getchar()) + 1) ++a[i - 'a'];
    for (i = 0; i < 26; i++) printf("%d ", a[i]);
}