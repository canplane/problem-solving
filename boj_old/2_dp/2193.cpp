#include <cstdio>

long long m[90][2] = { { 0, 1 } };  // big integer...

int main()
{
    int N, i;
    scanf("%d", &N);
    for (i = 1; i < N; i++)
        m[i][0] = (m[i][1] = m[i - 1][0]) + m[i - 1][1];
    printf("%lld", m[N - 1][0] + m[N - 1][1]);
}