#include <cstdio>
#define MIN2(x, y) ((x) <= (y) ? (x) : (y))

int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    while (K--) {
        if (N/2 >= M)  // = 안 붙이면 틀린다. N = 1, M = 0일 때 생각.
            N--;
        else
            M--;
    }
    printf("%d", MIN2(N/2, M));
}