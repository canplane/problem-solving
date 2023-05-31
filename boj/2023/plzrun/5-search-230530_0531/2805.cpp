using namespace std;
#include <cstdio>
#include <algorithm>

long A[1000000];
int N, M;

long _upper_bound(long lo, long hi)
{
    while (lo < hi) {
        long mi = lo + (hi - lo) / 2;
        long m = 0;
        for (int i = 0; i < N; i++)
            m += max((long)0, A[i] - mi);
        if (m < M)
            hi = mi;
        else
            lo = mi + 1;
    }
    return lo;
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%ld", &A[i]);
    long hi = A[0];
    for (int i = 0; i < N; i++)
        if (A[i] > hi)  hi = A[i];
    printf("%ld", _upper_bound(1, 1000000001) - 1);
}