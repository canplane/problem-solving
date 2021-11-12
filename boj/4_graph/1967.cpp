#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

vector<pair<int, int>> edges[10001];

pair<int, int> dfs(int v, int u) {
    int max_v = v, max_d = 0;
    for (auto& [w, weight] : edges[v]) {
        if (w == u) {
            continue;
        }
        auto [_max_v, _max_d] = dfs(w, v);
        _max_d += weight;
        if (_max_d > max_d) {
            max_d = _max_d, max_v = _max_v;
        }
    }
    return { max_v, max_d };
}

int main() {
    int n;
    scanf("%d", &n);
    
    int u, v, weight;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d %d", &u, &v, &weight);
        edges[u].push_back({ v, weight }), edges[v].push_back({ u, weight });
    }
    printf("%d", dfs(dfs(1, -1).first, -1).second);
}