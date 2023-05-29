#include <cstdio>

int A[1000000], B[1000000], C[2000000], N, M;

int main() {
    int i, j, k;
    scanf("%d %d", &N, &M);
    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);
    for (j = 0; j < M; j++)
        scanf("%d", &B[j]);
    
    k = i = j = 0;
    while (i < N && j < M)
        C[k++] = (A[i] < B[j]) ? A[i++] : B[j++];
    while (i < N)
        C[k++] = A[i++];
    while (j < M)
        C[k++] = B[j++];

    for (k = 0; k < N + M; k++)
        printf("%d ", C[k]);
}