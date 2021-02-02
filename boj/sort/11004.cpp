#include <cstdio>
#include <algorithm>

int a[5000000];

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    std::sort(a, a + N);
    printf("%d", a[K - 1]);
}