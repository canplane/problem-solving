#include <cstdio>
#define MAX_VERTICES 20000

bool edges[MAX_VERTICES + 1][MAX_VERTICES + 1];
bool visited[MAX_VERTICES + 1];
int part[MAX_VERTICES + 1];

// 메모리 초과
int dfs(int v, int N, int u) {
    int ret = 0;
    visited[v] = true;
    for (int w = 1; w <= N; w++) {
        if (edges[v][w] && part[w] == u) {
            u = v, ret++;
            break;
        }
    }
    part[v] = u;
    for (int w = 1; w <= N; w++) {
        if (!edges[v][w] && !visited[w])  // complement graph
            ret += dfs(w, N, u);
    }
    return ret;
}

int main() {
    int K, V, E, u, v, connected;
    scanf("%d", &K);
    while (K--) {
        scanf("%d %d", &V, &E);
        for (u = 1; u <= V; u++) {
            for (v = 1; v <= V; v++)
                edges[u][v] = false;
            visited[u] = false, part[u] = 0;
        }
        while (E--) {
            scanf("%d %d", &u, &v);
            edges[u][v] = edges[v][u] = true;
        }
        connected = 0;
        for (u = 1; u <= V; u++) {
            if (!visited[u])
                connected += 1 + dfs(u, V, u);
        }
        puts(connected < 3 ? "YES" : "NO");
    }
}