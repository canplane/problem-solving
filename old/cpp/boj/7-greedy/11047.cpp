#include <cstdio>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int coin[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &coin[i]);
        
    int ans = 0;
    for (int i = N - 1; i >= 0; i--) {
        // K = coin[i] * ans_increment + next_K;
        ans += K / coin[i];
        K %= coin[i];
        /*
        while (K >= coin[i])
            K -= coin[i], ++ans;
         */
    }
    printf("%d", ans);
}