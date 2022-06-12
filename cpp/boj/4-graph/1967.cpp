#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

vector<pair<int, int>> edges[10001];

pair<int, int> dfs(int v, int u) {
    int max_v = v, max_d = 0;
    for (auto& e : edges[v]) {
        if (e.first == u)
            continue;
        auto p = dfs(e.first, v);
        if (max_d < e.second + p.second)
            max_v = p.first, max_d = e.second + p.second;
    }
    return {max_v, max_d};
}

int main() {
    int u, v, weight;
    scanf("%*d");
    while (scanf("%d %d %d", &u, &v, &weight) != EOF) {
        edges[u].push_back({v, weight});
        edges[v].push_back({u, weight});
    }
    printf("%d", dfs(dfs(1, -1).first, -1).second);
}