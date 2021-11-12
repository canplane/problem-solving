#include <cstdio>

int T, N;
int next[1001];
bool visit[1001];

void dfs(int v) {
    while (!visit[v]) {
        visit[v] = true;
        v = next[v];
    }
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int v = 1; v <= N; v++) {
            scanf("%d", &next[v]);
            visit[v] = false;
        }

        int ans = 0;
        for (int v = 1; v <= N; v++) {
            if (!visit[v]) {
                ++ans, dfs(v);
            }
        }
        printf("%d\n", ans);
    }
}