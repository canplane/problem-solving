#include <cstdio>
#include <vector>
#define MAX_VERTICES 20000

// 인접 리스트를 쓸 거면 차라리 최적화가 된 벡터를 쓰자.
std::vector<int> edges[MAX_VERTICES + 1];
short int visited[MAX_VERTICES + 1];

bool dfs(int v, short int color) {
    visited[v] = color;
    for (auto it = edges[v].begin(); it != edges[v].end(); it++) {
        if (visited[*it] == color)
            return false;
        if (!visited[*it] && !dfs(*it, -color))
            return false;
    }
    return true;
}

int main() {
    int K, V, E, i, j;
    bool is_bipart;
    scanf("%d", &K);
    while (K--) {
        scanf("%d %d", &V, &E);
        while (E--) {
            scanf("%d %d", &i, &j);
            edges[i].push_back(j), edges[j].push_back(i);
        }
        is_bipart = true;
        for (i = 1; i <= V; i++)
            if (!visited[i] && !dfs(i, 1)) {
                is_bipart = false;
                break;
            }
        puts(is_bipart ? "YES" : "NO");
        for (i = 1; i <= V; i++)
            edges[i].resize(0), visited[i] = 0;
    }
}