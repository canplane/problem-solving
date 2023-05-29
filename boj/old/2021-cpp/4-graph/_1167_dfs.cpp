#include <cstdio>
#include <vector>
using namespace std;

vector<pair<int, int>> edges[100001];

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
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int u, v, weight;
        scanf("%d", &u);
        while (true) {
            scanf("%d", &v);
            if (v == -1)
                break;
            scanf("%d", &weight);
            edges[u].push_back({v, weight});
        }
    }
    printf("%d", dfs(dfs(1, -1).first, -1).second);
}