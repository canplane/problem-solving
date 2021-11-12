#include <cstdio>
#define MAXSZ 30

int sw[MAXSZ];

int main()
{
    int n, k;
    int bulb;
    bool is_bulb;

    scanf("%d", &n);
    for (int i = n - 1; i >= 0; i--)
        scanf("%d", &sw[i]);
    scanf("%d", &k);

    for (bulb = 0; ; bulb++) {
        is_bulb = true;
        for (int x = bulb, i = 0, pre_sw = n + 1; x; x >>= 1, i++) {
            if ((x % 2)) {
                if (pre_sw < sw[i]) {
                    is_bulb = false;
                    break;
                }
                pre_sw = sw[i];
            }
        }
        if (is_bulb && !--k)
            break;
    }
    
    printf("%d", bulb);
}