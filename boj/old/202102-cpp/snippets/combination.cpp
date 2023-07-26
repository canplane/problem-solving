#include <cstdio>
#include <algorithm>
using namespace std;

int num[8], rst[8], N, K;

void dfs(int pos, int idx) {
    if (pos == K) {
        for (int i = 0; i < K; i++)
            printf("%d ", rst[i]);
        printf("\n");
    }
    for (int i = idx; i < N; i++) {
        rst[pos] = num[i];
        dfs(pos + 1, i + 1);
    }
}

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
        scanf("%d", &num[i]);
    printf("\n");
    dfs(0, 0);
}