#include <cstdio>

int N, M;
bool edges[1001][1001];

bool visit[1001];

void dfs(int v) {
    visit[v] = true;
    for (int w = 1; w <= N; w++) {
        if (edges[v][w] && !visit[w]) {
            dfs(w);
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);

    int u, v;
    while (M--) {
        scanf("%d %d", &u, &v);
        edges[u][v] = edges[v][u] = true;
    }

    int ans = 0;
    for (v = 1; v <= N; v++) {
        if (!visit[v]) {
            ++ans, dfs(v);
        }
    }
    printf("%d", ans);
}