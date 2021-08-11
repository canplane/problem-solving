#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int K, V, E;
vector<int> edges[20001];
int visit[20001];

bool dfs(int v, int color) {
    visit[v] = color;
    for (auto w : edges[v]) {
        if (!visit[w] && !dfs(w, -color)) {
            return false;
        }
        else if (visit[w] == color) {
            return false;
        }
    }
    return true;
}

int main() {
    scanf("%d", &K);
    while (K--) {
        scanf("%d %d", &V, &E);
        memset(edges, 0, sizeof(edges));
        memset(visit, 0, sizeof(visit));

        int u, v;
        while (E--) {
            scanf("%d %d", &u, &v);
            edges[u].push_back(v), edges[v].push_back(u);
        }

        bool bipart = true;
        for (int v = 1; v <= V; v++) {
            if (!visit[v] && !dfs(v, 1)) {
                bipart = false;
                break;
            }
        }
        printf(bipart ? "YES\n" : "NO\n");
    }
}