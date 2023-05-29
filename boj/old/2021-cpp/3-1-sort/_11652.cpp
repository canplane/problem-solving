#include <cstdio>
#include <map>

std::map<long long, int> m;

int main()
{
    int N, max = 0;
    long long d;

    scanf("%d", &N);
    while (N--)
        scanf("%lld", &d), m[d]++;
    for (auto e : m)
        if (max < e.second)  // map은 순서대로 나오나 봄. -> map은 R-B 트리다! 그래서 가능!
            max = e.second, d = e.first;
    printf("%lld", d);
}