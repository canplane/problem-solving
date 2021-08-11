#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

vector<pair<int, int>> edges[100001];

pair<int, int> dfs(int v, int u) {
    int dep1 = 0, dep2 = 0;
    int len = 0;
    for (auto& [w, weight] : edges[v]) {
        if (w != u) {
            auto [d, l] = dfs(w, v);
            d += weight;

            if (d > dep1) {
                dep2 = dep1, dep1 = d;
            }
            else if (d > dep2) {
                dep2 = d;
            }
            if (l > len) {
                len = l;
            }
        }
    }
    if (dep1 + dep2 > len) {
        len = dep1 + dep2;
    }
    return { dep1, len };  // depth, length
}

int main() {
    int V;
    scanf("%d", &V);
    for (int i = 0; i < V; i++) {
        int u, v, weight;
        scanf("%d", &u);
        while (true) {
            scanf("%d", &v);
            if (v == -1) {
                break;
            }
            scanf("%d", &weight);
            edges[u].push_back({ v, weight });
        }
    }
    printf("%d", dfs(1, -1).second);
}