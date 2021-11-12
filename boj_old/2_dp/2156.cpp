#include <cstdio>
#define MAX(x, y) ((x) < (y) ? (y) : (x))

int in[10000], f[10000];

int main()
{
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &in[i]);
    
    f[0] = in[0], f[1] = in[1] + in[0], f[2] = MAX(in[2] + f[0], f[1]);
    for (i = 2; i < n; i++)
        f[i] = MAX(MAX(in[i] + in[i - 1] + f[i - 3], in[i] + f[i - 2]), f[i - 1]);
    printf("%d", f[n - 1]);
}