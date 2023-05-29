#include <cstdio>
#include <cmath>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int ans = 0;
    while (true) {
        printf("<%d>\n", N);
        if (abs(N - K) < 1 + abs(2*N - K))
            break;
        N *= 2, ++ans;
    }
    ans += abs(N - K);

    printf("%d", ans);
}