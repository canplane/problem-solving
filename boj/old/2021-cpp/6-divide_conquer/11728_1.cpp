#include <cstdio>
#include <algorithm>

int C[2000000], N, M;

int main() {
    int i;
    scanf("%d %d", &N, &M);
    for (i = 0; i < N + M; i++)
        scanf("%d", &C[i]);
    std::sort(C, C + N + M);
    for (i = 0; i < N + M; i++)
        printf("%d ", C[i]);       
}