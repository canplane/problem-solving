#include <cstdio>
#include <cmath>
#define MAX_N 30

int sw[MAX_N];
int cross[MAX_N * (MAX_N - 1) / 2], cross_top = -1;

int main()
{
    int N, K, ans, ans_max;
    int i, j;
    bool b;

    scanf("%d", &N);
    for (i = N - 1; i >= 0; i--)
        scanf("%d", &sw[i]);
    scanf("%d", &K);

    for (i = 0; i < N; i++) {
        for (j = i + 1; j < N; j++) {
            if (sw[i] < sw[j])
                cross[++cross_top] = (1 << i) | (1 << j);
        }
    }

    ans_max = pow(2, N);
    for (ans = 0; ans < ans_max; ans++) {
        b = true;
        for (i = 0; i <= cross_top; i++) {
            if ((ans & cross[i]) == cross[i]) {
                b = false;
                break;
            }
        }
        if (b) K--;
        if (!K)
            break;
    }
    printf("%d", K ? -1 : ans);
    
    //for (int i = 0; i <= cross_top; i++)
        //printf("%02X ", cross[i]);
}