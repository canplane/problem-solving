#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int map[102][102], dist[102][102], N;
int dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1};

void dfs(int y, int x) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if (map[ny][nx] == 1) {
            map[ny][nx] = map[y][x];
            dfs(ny, nx);
        }
    }
}

#define INF 0x7fffffff
void bfs() {
    queue<pair<int, int>> q;
    pair<int, int> p;
    int y, x;

    for (y = 1; y <= N; y++)
        for (x = 1; x <= N; x++)
            if (map[y][x])
                q.push(make_pair(y, x)), dist[y][x] = 0;
    
    int ans = INF, prev_d = 0;
    while (!q.empty()) {
        p = q.front(), q.pop();
        y = p.first, x = p.second;

        if (prev_d != dist[y][x]) {  // pruning
            if (ans != INF)
                break;
            prev_d = dist[y][x];
        }
        
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny == 0 || ny == N + 1 || nx == 0 || nx == N + 1)
                continue;
            if (map[ny][nx]) {
                if (map[ny][nx] != map[y][x])
                    ans = min(ans, dist[ny][nx] + dist[y][x]);
                continue;
            }
            map[ny][nx] = map[y][x], dist[ny][nx] = dist[y][x] + 1;
            q.push(make_pair(ny, nx));
        }
    }
    printf("%d", ans);
}

int main() {
    int y, x;
    scanf("%d", &N);
    for (y = 1; y <= N; y++)
        for (x = 1; x <= N; x++)
            scanf("%d", &map[y][x]);
    int domain = 0;
    for (y = 1; y <= N; y++)
        for (x = 1; x <= N; x++)
            if (map[y][x] == 1) {
                map[y][x] = --domain;
                dfs(y, x);
            }
    bfs();
}