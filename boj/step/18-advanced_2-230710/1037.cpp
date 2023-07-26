using namespace std;
#include <cstdio>
#include <algorithm>

int A[50];

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    sort(A, A + N);
    printf("%d", A[0] * A[N - 1]);
}