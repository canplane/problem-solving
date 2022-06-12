/* 카운팅 정렬! */

#include <cstdio>

int a[10001];

int main()
{
    int N, d, i;
    scanf("%d", &N);
    while (N--)
        scanf("%d", &d), a[d]++;
    for (i = 1; i < 10001; i++)
        while (a[i]--) printf("%d\n", i);
}
