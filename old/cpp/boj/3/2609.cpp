#include <cstdio>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int a, b, g, l;
    scanf("%d %d", &a, &b);
    g = gcd(a, b), l = (a / g) * b;
    printf("%d\n%d\n", g, l);
}