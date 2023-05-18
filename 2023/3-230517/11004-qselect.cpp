#include <cstdio>
#include <algorithm>

int A[5'000'000];
int N, K;

int main()
{
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d", A + i);
    }
    std::nth_element(A, A + K - 1, A + N);
    printf("%d", A[K - 1]);
}