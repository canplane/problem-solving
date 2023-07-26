#include <cstdio>
#define MIN2(x, y) ((x) < (y) ? (x) : (y))

struct Foo {
    int twos = 0, fives = 0;
    const Foo operator+(const Foo& a) const {
        Foo foo;
        foo.twos = twos + a.twos, foo.fives = fives + a.fives;
        return foo;
    }
    const Foo operator-(const Foo& a) const {
        Foo foo;
        foo.twos = twos - a.twos, foo.fives = fives - a.fives;
        return foo;
    }
};

Foo f(int n) {
    Foo ret;
    int k;
    for (k = n; k; ) ret.twos += (k /= 2);
    for (k = n; k; ) ret.fives += (k /= 5);
    return ret;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    Foo foo = f(n) - (f(m) + f(n - m));
    printf("%d", MIN2(foo.twos, foo.fives));
}