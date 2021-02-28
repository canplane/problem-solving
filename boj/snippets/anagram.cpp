#include <cstdio>
#include <algorithm>
using namespace std;

int A[8], N;

void f(int idx) {
    if (idx == N) {
        for (int i = 0; i < N; i++)
            printf("%d ", A[i]);
        printf("\n");
    }
    for (int i = idx; i < N; i++) {
        swap(A[idx], A[i]);
        f(idx + 1);
        swap(A[idx], A[i]); 
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    printf("\n");
    f(0);
}