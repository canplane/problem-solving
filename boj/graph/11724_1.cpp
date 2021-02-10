#include <cstdio>
#define MAX_VERTICES 1000

bool edges[MAX_VERTICES + 1][MAX_VERTICES + 1];
// visited[v]를 edges[v][0]에 합쳤다!

void dfs(int v, int N) {
    edges[v][0] = true;
    for (int w = 1; w <= N; w++)
        if (edges[v][w] && !edges[w][0])
            dfs(w, N);
}

int main() {
    int N, M, u, v, ans;
    scanf("%d %d", &N, &M);
    while (M--) {
        scanf("%d %d", &u, &v);
        edges[u][v] = edges[v][u] = true;
    }

    ans = 0;
    for (u = 1; u <= N; u++)
        if (!edges[u][0])
            dfs(u, N), ++ans;
    printf("%d", ans);
}
