#include <cstdio>

int np[1000001];
void eratos()
{
    np[0] = np[1] = true;
    for (int i = 2; i <= 500000; i++) {
        if (!np[i]) {
            for (int j = 2 * i; j <= 1000000; j += i) {
                np[j] = true;
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    eratos();

    while (T--) {
        int x;
        scanf("%d", &x);
        
        int cnt = 0;
        for (int i = 2; i <= x / 2; i++) {
            cnt += !np[i] && !np[x - i];
        }
        printf("%d\n", cnt);
    }
}