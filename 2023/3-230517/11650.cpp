#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

pair<int, int> v[100000];

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &v[i].first, &v[i].second);
    }
    sort(v, v + N);
    for (int i = 0; i < N; i++) {
        printf("%d %d\n", v[i].first, v[i].second);
    }
}