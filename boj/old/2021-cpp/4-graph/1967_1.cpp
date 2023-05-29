/* 내 풀이 */

#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

vector<pair<int, int>> edges[10001];

pair<int, int> dfs(int v, int u) {
    int dia = 0, d1 = 0, d2 = 0, d;
    for (auto &e : edges[v]) {
        if (e.first == u)
            continue;
        auto p = dfs(e.first, v);
        d = e.second + p.second;
        if (d > d1)
            d2 = d1, d1 = d;
        else if (d > d2)
            d2 = d;
        dia = max(dia, p.first);
    }
    return {max(dia, d1 + d2), d1};  // v가 루트인 트리에서의 최대 지름, 최대 높이
}

int main() {
    int u, v, weight;
    scanf("%*d");
    while (scanf("%d %d %d", &u, &v, &weight) != EOF) {
        edges[u].push_back({v, weight});
        edges[v].push_back({u, weight});
    }
    auto p = dfs(1, -1);
    printf("%d", max(p.first, p.second));
}