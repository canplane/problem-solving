#include <cstdio>
#define MAXSZ 5000000

bool eratos[MAXSZ + 1];

void init() {
    int i, j;
    eratos[1] = true;
    for (i = 2; i <= MAXSZ / 2; i++) {
        if (!eratos[i])
            continue;
        for (j = 2 * i; j <= MAXSZ; j += i)
            eratos[j] = true;
    }
}

int main() {
    int N, i;
    init();
    scanf("%d", &N);

    i = 2;
    while (N > 1) {
        if (N % i) {
            i++;
            continue;
        }
        printf("%d\n", i);
        N /= i;
    }
}