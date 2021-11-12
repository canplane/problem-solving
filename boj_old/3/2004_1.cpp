#include <cstdio>
#define MIN2(x, y) ((x) < (y) ? (x) : (y))

int f(int n, int p) {
    int ret = 0;
    while (n /= p) ret += n;
    return ret;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d", MIN2(f(n, 2) - f(m, 2) - f(n - m, 2), f(n, 5) - f(m, 5) - f(n - m, 5)));
}