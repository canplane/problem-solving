#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int K, V, E;

int visit[20001];

// edges를 스택 영역으로 보내서 메모리 차지 줄임
bool dfs(vector<int> edges[], int v, int color) {
    bool bipart = true;

    visit[v] = color;
    for (auto w : edges[v]) {
        if (!visit[w] && !dfs(edges, w, -color)) {
            return false;
        }
        else if (visit[w] == color) {
            return false;
        }
    }

    return bipart;
}

int main() {
    scanf("%d", &K);
    while (K--) {
        scanf("%d %d", &V, &E);

        vector<int> edges[V + 1];
        memset(visit, 0, sizeof(visit));

        int u, v;
        while (E--) {
            scanf("%d %d", &u, &v);
            edges[u].push_back(v), edges[v].push_back(u);
        }

        bool bipart = true;
        for (int v = 1; v <= V; v++) {
            if (!visit[v] && !dfs(edges, v, 1)) {
                bipart = false;
                break;
            }
        }
        printf(bipart ? "YES\n" : "NO\n");
    }
}