#include <cstdio>
#include <algorithm>

int a[5000000];

int main()
{
    int N, K, i;
    scanf("%d %d", &N, &K);
    for (i = 0; i < N; i++) scanf("%d", a + i);
    std::nth_element(a, a + K - 1, a + N);
    printf("%d", a[K - 1]);
}