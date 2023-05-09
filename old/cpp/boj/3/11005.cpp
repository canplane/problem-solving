#include <cstdio>

void f(int n, int b) {
    int r;
    if (!n) return;
    f(n / b, b);
    r = n % b;
    r += (r < 10) ? 48 : 55;
    putchar(r);
}

int main() {
    int N, B;
    scanf("%d %d", &N, &B);
    f(N, B);   
}