#include <cstdio>
#include <map>
using namespace std;

map<long long, int> d;

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        long long k;
        scanf("%lld", &k);
        d[k]++;
    }

    auto ans = d.begin();
    for (auto it = d.begin(); it != d.end(); it++) {
        if (it->second > ans->second)
            ans = it;
    }
    printf("%lld", ans->first);
}