#include <cstdio>

char buf[102];

int main()
{
    int lc, uc, d, s;
    while (fgets(buf, 102, stdin)) {
        lc = uc = d = s = 0;
        for (int i = 0; buf[i]; i++) {
            if (buf[i] > 96) lc++;
            else if (buf[i] > 64) uc++;
            else if (buf[i] > 47) d++;
            else if (buf[i] == ' ') s++;
        }
        printf("%d %d %d %d\n", lc, uc, d, s);
    }
}