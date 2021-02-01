#include <cstdio>
#include <algorithm>

long long a[100000], ans;

int main()
{
    int N, i, max_cnt, cnt;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%lld", &a[i]);
    std::sort(a, a + N);

    ans = a[0], max_cnt = cnt = 1;
    for (i = 1; i < N; i++) {
        if (a[i] != a[i - 1])
            cnt = 0;
        ++cnt;
        if (max_cnt < cnt)
            ans = a[i - 1], max_cnt = cnt;
    }
    printf("%lld", ans);
}