// using naive array for sorting is not capable!!

#include <cstdio>
#include <array>
#include <algorithm>
using namespace std;

array< array<int, 2>, 100000> v;

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &v[i][0], &v[i][1]);
    }
    sort(v.begin(), v.begin() + N);
    for (int i = 0; i < N; i++) {
        printf("%d %d\n", v[i][0], v[i][1]);
    }
}