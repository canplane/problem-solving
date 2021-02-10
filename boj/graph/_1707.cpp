#include <cstdio>
#include <vector>
#include <queue>
#define MAX_VERTICES 20000

vector<int> edges[MAX_VERTICES + 1];

short int visited[MAX_VERTICES + 1];

bool bfs(int v, int color, int N) {
    std::queue<int> q;
    q.push(v), visited[v] = color;
    while (!q.empty()) {
        v = q.front(), q.pop();
        for (int w = 1; w <= N; w++) {
            if (edges[v][w]) {
                if (!visited[w])
                    q.push(w), visited[w] = -color;
                else if (visited[w] == color)
                    return false;
            }
        }
        color *= -1;
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
                edges[i].resize(0);
            visited[i] = 0;
        }
        while (E--) {
            scanf("%d %d", &i, &j);
            edges[i].push_back(j), edges[j].push_back(i);
        }
        is_bipart = true;
        for (i = 1; i <= MAX_VERTICES; i++)
            if (!visited[i] && !bfs(i, 1, V)) {
                is_bipart = false;
                break;
            }
        puts(is_bipart ? "YES" : "NO");
    }
}