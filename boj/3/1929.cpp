#include <cstdio>
#define MAXSZ 100000

bool eratos[MAXSZ + 1];  // true면 합성수

void init() {
    int i, j;
    eratos[1] = true;  // 주의
    for (i = 2; i <= MAXSZ / 2; i++) {
        if (eratos[i])
            continue;
        for (j = 2 * i; j <= MAXSZ; j += i)
            eratos[j] = true;
    }
}

int main() {
    int M, N;
    init();
    scanf("%d %d", &M, &N);
    while (M <= N) {
        if (!eratos[M]) printf("%d\n", M);
        M++;
    }
}