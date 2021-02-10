#include <cstdio>
#define MAX_VERTICES 1000

bool edges[MAX_VERTICES + 1][MAX_VERTICES + 1];
bool visited[MAX_VERTICES + 1];

void dfs(int v, int N) {
    visited[v] = true;
    for (int w = 1; w <= N; w++)
        if (edges[v][w] && !visited[w])
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
        if (!visited[u])  // 간선이 없는 노드도 있을 수 있다!
            dfs(u, N), ++ans;
    printf("%d", ans);
}
