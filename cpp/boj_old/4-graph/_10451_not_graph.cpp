// 그래프 이론 없이도 단순히 순열을 따라가면서 풀 수도 있는 거였다!

#include <cstdio>
#define MAX_N 1000

int seq[MAX_N + 1];

int main() {
    int T, N;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++)
            scanf("%d", &seq[i]);
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            if (!seq[i])
                continue;
            ++ans;
            for (int cur = i, tmp; seq[cur]; cur = tmp)
                tmp = seq[cur], seq[cur] = 0;
        }
        printf("%d\n", ans);
    }
}