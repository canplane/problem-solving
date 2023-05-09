#include <cstdio>
#include <vector>
#define MAX_VERTICES 1000

std::vector<int> edges[MAX_VERTICES + 1];
bool visited[MAX_VERTICES + 1];

void dfs(int v) {
    visited[v] = true;
    for (auto it = edges[v].begin(); it != edges[v].end(); it++) {
        if (!visited[*it])
            dfs(*it);
    }
}

int main() {
    int T, N, u, v, ans;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (u = 1; u <= N; u++) {
            scanf("%d", &v);
            edges[u].push_back(v);
        }
        ans = 0;
        for (u = 1; u <= N; u++) {
            if (!visited[u])
                ++ans, dfs(u);
        }
        printf("%d\n", ans);
        for (u = 1; u <= N; u++)
            edges[u].resize(0), visited[u] = false;
    }
}