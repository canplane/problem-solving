#include <cstdio>

long long int gcd(long long int a, long long int b) {
    if (!b)
        return a;
    return gcd(b, a % b);
}

int main() {
    long long int a, b, t, r;
    scanf("%lld %lld", &a, &b);
    if (a < b)
        t = a, a = b, b = t;
    r = gcd(a, b);
    while (r--)
        putchar('1');
}