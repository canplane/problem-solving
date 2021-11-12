#include <cstdio>
#include <algorithm>
#define MAX_N 1000000

using namespace std;

int v[MAX_N];

int main()
{
    int N, i;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &v[i]);
    sort(v, v + N);
    for (i = 0; i < N; i++)
        printf("%d\n", v[i]);
}