#include <cstdio>
#include <utility>
#include <algorithm>
#define MAX_N 100000

using namespace std;

pair<int, int> p[MAX_N];

int main()
{
    int N, i;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d %d", &p[i].second, &p[i].first);
    sort(p, p + N);
    for (i = 0; i < N; i++)
        printf("%d %d\n", p[i].second, p[i].first);
}