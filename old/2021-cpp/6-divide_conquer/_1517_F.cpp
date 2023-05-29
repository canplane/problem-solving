#include <cstdio>
#include <algorithm>

int A[500000], N;

void bubble() {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (N - 1) - i; j++) {
            if (A[j] > A[j + 1]) {
                std::swap(A[j], A[j + 1]);
                ++cnt;
            }
        }
    }
    printf("%d", cnt);
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    bubble();
}