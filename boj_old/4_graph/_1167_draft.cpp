#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<pair<int, int>> edges[100001];

pair<int, int> dfs(int v, int u) {
    int d1 = 0, d2 = 0, d;
    int dia = -1;
    for (auto& e : edges[v]) {
        if (e.first == u)
            continue;
        auto p = dfs(e.first, v);
        d = e.second + p.first, dia = max(dia, p.second);
        if (d > d1)
            d2 = d1, d1 = d;
        else if (d > d2)
            d2 = d;
    }
    return {d1, max(dia, d1 + d2)};
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
    int diameter = 0;
    auto p = dfs(1, -1);
    printf("%d", max(p.first, p.second));
}