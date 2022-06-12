#include <cstdio>

bool eratos[1001];

int main() {
    int i, j;
    for (i = 2; i <= 500; i++) {
        if (eratos[i])
            continue;
        for (j = 2 * i; j <= 1000; j += i)
            eratos[j] = true;
    }

    int N, tmp, ans = 0;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &tmp);
        if (tmp != 1 && !eratos[tmp])  // 1 주의!
            ++ans;
    }
    printf("%d", ans);
}