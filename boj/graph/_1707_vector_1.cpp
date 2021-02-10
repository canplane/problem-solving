#include <cstdio>
#include <vector>

template <typename T>
bool dfs(T edges[], short int visited[], int v, short int color) {
    visited[v] = color;
    for (auto it = edges[v].begin(); it != edges[v].end(); it++) {
        if (visited[*it] == color)
            return false;
        if (!visited[*it] && !dfs(edges, visited, *it, -color))
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

        std::vector<int> edges[V + 1];  // 스택 영역에 STL 위치 -> 끝나면 자동 소멸
        short int visited[V + 1];  //
        for (i = 1; i <= V; i++)
            visited[i] = 0;

        while (E--) {
            scanf("%d %d", &i, &j);
            edges[i].push_back(j), edges[j].push_back(i);
        }
        is_bipart = true;
        for (i = 1; i <= V; i++)
            if (!visited[i] && !dfs(edges, visited, i, 1)) {
                is_bipart = false;
                break;
            }
        puts(is_bipart ? "YES" : "NO");
    }
}