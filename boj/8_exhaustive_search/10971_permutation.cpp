#include <cstdio>
#include <algorithm>

int W[10][10], N;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &W[i][j]);
    
    int walk[N];
    for (int i = 0; i < N; i++)
        walk[i] = i;

    int ans = 0x7fffffff;
    do {
        int sum = 0, tmp;
        for (int i = 1; i < N; i++) {
            if (!(tmp = W[walk[i - 1]][walk[i]]))
                goto end;
            sum += tmp;
        }
        if (!(tmp = W[walk[N - 1]][walk[0]]))
            goto end;
        sum += tmp;

        ans = std::min(ans, sum);
        end:;
    } while (std::next_permutation(walk + 1, walk + N));
    printf("%d", ans);
}