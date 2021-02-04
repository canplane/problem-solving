#include <cstdio>

int lc, uc, n, s;

int main()
{
    int c;
    bool b;
    while (true) {
        c = getchar();
        if (c == '\n') {
            printf("%d %d %d %d\n", lc, uc, n, s);
            lc = uc = n = s = 0;
            b = true;
            continue;
        }
        else if (c == -1) {
            if (!b) printf("%d %d %d %d\n", lc, uc, n, s);  // 개행 뒤에 EOF가 나올 수 있음.
            break;
        }
        else if (c > 96) ++lc;
        else if (c > 64) ++uc;
        else if (c > 47) ++n;
        else ++s;
        b = false;
    }
}