#include <cstdio>

char s[1000001];

void f(int len) {
    if (len <= 0)
        return;
    f(len - 3);
    if (len >= 3)
        putchar('0' + 4 * s[len - 3] + 2 * s[len - 2] + s[len - 1]);
    else if (len == 2)
        putchar('0' + 2 * s[0] + s[1]);
    else
        putchar('0' + s[0]);   
}

int main() {
    char c;
    int len = 0;
    while ((c = getchar()) != EOF && c != '\n') {  // 개행 주의
        s[len++] = c - '0';
    }
    f(len);
}