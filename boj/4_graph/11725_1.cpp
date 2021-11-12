#include <cstdio>
#include <vector>
using namespace std;

vector<int> edges[100001];
int parents[100001];

void dfs(int v) {
    for (auto w : edges[v]) {
        if (w == parents[v]) {
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
    while (~scanf("%d %d", &u, &v)) {  // for (i = 0; i < N - 1; i++) {
        edges[u].push_back(v), edges[v].push_back(u);
    }

    dfs(1);
    for (int i = 2; i <= N; i++) {
        printf("%d\n", parents[i]);
    }
}