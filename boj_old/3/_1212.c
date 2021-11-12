#include <stdio.h>

char s[333335], t[4];

char *otob(int o) {
    int idx = 3;
    while (o) {
        t[--idx] = o % 2 + '0';
        o /= 2;
    }
    while (idx) {
        t[--idx] = '0';
    }
    return t + idx;
}
char *otob_first(int o) {
    if (!o) {
        t[2] = '0';
        return t + 2;
    }
    int idx = 3;
    while (o) {
        t[--idx] = o % 2 + '0';
        o /= 2;
    }
    return t + idx;
}

int main() {
    scanf("%s", s);
    
    printf("%s", otob_first(s[0] - '0'));
    for (int i = 1; s[i]; i++)
        printf("%s", otob(s[i] - '0'));
}