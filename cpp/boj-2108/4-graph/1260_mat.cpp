#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int N, M, V;
bool edges[1001][1001];

bool visit[1001];

void dfs(int v) {
    visit[v] = true;
    printf("%d ", v);
    for (int w = 1; w <= N; w++) {
        if (edges[v][w] && !visit[w]) {
            dfs(w);
        }
    }
}

void bfs(int v) {
    queue<int> q;
    q.push(v), visit[v] = true;
    while (!q.empty()) {
        v = q.front(), q.pop();
        printf("%d ", v);
        for (int w = 1; w <= N; w++) {
            if (edges[v][w] && !visit[w]) {
                q.push(w), visit[w] = true;
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &N, &M, &V);
    
    int x, y;
    while (M--) {
        scanf("%d %d", &x, &y);
        edges[x][y] = edges[y][x] = true;
    }

    dfs(V);
    printf("\n");

    memset(visit, 0, sizeof(visit));
    bfs(V);
}