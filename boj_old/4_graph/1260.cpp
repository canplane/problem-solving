#include <cstdio>
#include <queue>
#define MAX_VERTICES 1000

bool edges[MAX_VERTICES + 1][MAX_VERTICES + 1];

bool dfs_visited[MAX_VERTICES + 1];
void dfs(int v, int n) {
    printf("%d ", v), dfs_visited[v] = true;
    for (int w = 1; w <= n; w++)
        if (edges[v][w] && !dfs_visited[w])
            dfs(w, n);
}

bool bfs_visited[MAX_VERTICES + 1];
void bfs(int v, int n) {
    std::queue<int> q;
    q.push(v), bfs_visited[v] = true;
    while (!q.empty()) {
        v = q.front(), q.pop();
        printf("%d ", v);
        for (int w = 1; w <= n; w++)
            if (edges[v][w] && !bfs_visited[w])
                q.push(w), bfs_visited[w] = true;
    }
}

int main() {
    int N, M, V, u, v;
    scanf("%d %d %d", &N, &M, &V);
    while (M--) {
        scanf("%d %d", &u, &v);
        edges[u][v] = edges[v][u] = true;
    }
    dfs(V, N), printf("\n");
    bfs(V, N), printf("\n");
}