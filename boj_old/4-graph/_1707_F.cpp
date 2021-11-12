#include <cstdio>
#define MAX_VERTICES 20000

/*
sizeof(bool) == 1
메모리 제한이 256 MB인데, 20000^2 B = 4 * 10^8 B = 4 * 10^2 MB = 400 MB : 메모리 초과!
인접 행렬은 메모리 용량 먼저 보고 써야 한다.
안 되면 vector<int> 쓰거나, 인접 리스트 구현.
 */
bool edges[MAX_VERTICES + 1][MAX_VERTICES + 1];
short int visited[MAX_VERTICES + 1];

bool dfs(int v, int color, int N) {
    visited[v] = color;
    for (int w = 1; w <= N; w++) {
        if (!edges[v][w])
            continue;
        if (visited[w] == color)
            return false;
        if (!visited[w] && !dfs(w, -color, N))
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
        for (i = 1; i <= V; i++) {
            for (j = 1; j <= V; j++)
                edges[i][j] = false;
            visited[i] = 0;
        }
        while (E--) {
            scanf("%d %d", &i, &j);
            edges[i][j] = edges[j][i] = true;
        }
        is_bipart = true;
        for (i = 1; i <= V; i++)
            if (!visited[i] && !dfs(i, 1, V)) {
                is_bipart = false;
                break;
            }
        puts(is_bipart ? "YES" : "NO");
    }
}