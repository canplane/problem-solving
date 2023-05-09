#include <cstdio>

void f(int n, int b) {
    if (n / b) f(n / b, b);
    printf("%d ", n % b);
}

int main() {
    int A, B, m, sum, tmp, i;
    scanf("%d %d %d", &A, &B, &m);

    sum = 0;
    while (m--) {
        scanf("%d", &tmp);
        sum = A * sum + tmp;
    }
    f(sum, B);
}