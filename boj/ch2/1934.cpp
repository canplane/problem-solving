#include <cstdio>

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
    int T, a, b;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &a, &b);
        printf("%d\n", a / gcd(a, b) * b);
    }
}