#include <cstdio>
#include <vector>
using namespace std;

vector<int> edges[100001];
int parents[100001];

void dfs(int v) {
    for (auto w : edges[v]) {
        if (parents[w]) {
            continue;
        }
        parents[w] = v;
        dfs(w);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    int u, v;
    while (~scanf("%d %d", &u, &v)) {
        edges[u].push_back(v), edges[v].push_back(u);
    }

    parents[1] = -1;
    dfs(1);
    for (int i = 2; i <= N; i++) {
        printf("%d\n", parents[i]);
    }
}