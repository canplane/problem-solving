/* 이상하게 이게 더 느리다! */

#include <cstdio>
#include <algorithm>

long long a[100000], ans, prev;

int main()
{
    int N, i, max_cnt, cnt;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%lld", &a[i]);
    std::sort(a, a + N);

    ans = prev = a[0], max_cnt = cnt = 1;
    for (i = 1; i < N; i++) {
        if (a[i] != prev) {
            if (cnt > max_cnt)
                max_cnt = cnt, ans = prev;
            prev = a[i], cnt = 1;
        } else
            cnt++;
    }
    if (cnt > max_cnt)
        max_cnt = cnt, ans = prev;

    printf("%lld", ans);
}