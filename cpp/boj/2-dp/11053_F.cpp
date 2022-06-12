/* 틀림! 왜 틀린지는 모르겠지만 일단 비효율적. */

#include <cstdio>
#define MAX(x, y) ((x) < (y) ? (y) : (x))

struct { int key, len; } li[1000];
int top = -1;

int main()
{
    int N, num, len, i, j;

    scanf("%d", &N);
    while (N--) {
        scanf("%d", &num);
        len = 0;
        for (i = 0; i <= top; i++) {
            if (li[i].key >= num) break;
            len = MAX(len, li[i].len);
        }
        if (top != -1 && li[i].key == num) continue;
        for (j = ++top; j > i; j--) li[j] = li[j - 1];
        li[i].key = num, li[i].len = len + 1;
    }
    len = 0;
    for (i = 0; i <= top; i++) {
        printf("{%d,%d} ", li[i].key, li[i].len);
        len = MAX(len, li[i].len);
    }
    printf("\n");
    printf("%d", len);
}