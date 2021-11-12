#include <stdio.h>

// 이전 코드
/*
#define ABS(x) ((x) < 0 ? -(x) : (x))
void f(int n) {
    int r = ABS(n) % 2;
    n -= r;
    if (n) f(-n / 2);
    printf("%d", r);
}
*/

void f(int n) {
    int q = n / (-2) + (n < 0 && n % (-2));
    if (q) f(q);
    printf("%d", n - (-2) * q);
}

int main() {
    int d;
    scanf("%d", &d);
    f(d);
}

/**
 * 13 = -2 * (-6) + 1
 * -13 = -2 * (6) - 1 = -2 * 7 + 1
 * 
 * C 언어는 파이썬과 달리, 음수에서 나눗셈을 할 때 몫을 내리지 않고, 버린다!
 * 따라서 나머지가 음수가 된다.
 */