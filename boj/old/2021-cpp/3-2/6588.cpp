#include <cstdio>
#define MAXSZ 1000000

bool eratos[MAXSZ + 1];

void init() {
    int i, j;
    eratos[1] = true;
    for (i = 2; i <= MAXSZ / 2; i++) {
        if (eratos[i])
            continue;
        for (j = 2 * i; j <= MAXSZ; j += i)
            eratos[j] = true;
    }
}

int main() {
    int num, i;
    bool flag;
    init();
    while (true) {
        scanf("%d", &num);
        if (!num)
            break;
        flag = true;
        for (i = 2; i <= num / 2; i++) {
            if (eratos[i] || eratos[num - i])
                continue;
            flag = false;
            printf("%d = %d + %d\n", num, i, num - i);
            break;
        }
        if (flag)
            printf("Mooyaho!\n");
    }
}