#include <cstdio>

int card[52];

int s(char c)
{
    switch (c) {
        case 'P':   return 0;
        case 'K':   return 1;
        case 'H':   return 2;
        case 'T':   return 3;
    }
    return -1;
}

int main()
{
    char c;
    int xy;
    while (scanf("%c%d", &c, &xy) == 2) {
        int idx = 13 * s(c) + (xy - 1);     // xy는 1부터 시작!
        if (card[idx]) {
            puts("GRESKA");
            return 0;
        }
        card[idx] = 1;
    }

    int cnt = 0;
    for (int i = 0; i < 52; i++) {
        if (!card[i])   cnt++;
        if ((i + 1) % 13 == 0) {
            printf("%d ", cnt);
            cnt = 0;
        }
    }
}