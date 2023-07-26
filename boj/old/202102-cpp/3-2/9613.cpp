#include <cstdio>

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
    int t, n, v[100], i, j;
    long long int sum;  // 하...
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        sum = 0;
        for (i = 0; i < n; i++)
            scanf("%d", &v[i]);
        for (i = 0; i < n; i++)
            for (j = i + 1; j < n; j++)
                sum += gcd(v[i], v[j]);
        printf("%lld\n", sum);
    }
}