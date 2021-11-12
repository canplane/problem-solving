#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;

int map[102][102], dist[102][102], N;
int dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1};

void dfs(int y, int x, int nth) {
    map[y][x] = nth;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if (map[ny][nx] == 1)
            dfs(ny, nx, nth);
    }
}

int bfs(int parts) {
    int y, x;
    queue<tuple<int, int, int>> q[parts + 1];
    tuple<int, int, int> t;

    for (y = 1; y <= N; y++)
        for (x = 1; x <= N; x++)
            if (map[y][x]) {
                map[y][x] *= -1;
                q[map[y][x]].push({y, x, 0});
            }
    int cur = 1;
    while (true) {
        int sz = q[cur].size();
        while (sz--) {
            t = q[cur].front(), q[cur].pop();
            y = get<0>(t), x = get<1>(t), dist[y][x] = get<2>(t), map[y][x] = cur;
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if (ny == 0 || ny == N + 1 || nx == 0 || nx == N + 1)
                    continue;
                if (map[ny][nx]) {
                    if (map[ny][nx] == map[y][x])
                        continue;
                    return dist[ny][nx] + dist[y][x];
                }
                q[cur].push({ny, nx, dist[y][x] + 1});
            }
        }
        cur++;
        if (cur > parts)
            cur = 1;
    }
    return -1;
}

int main() {
    int y, x, nth;
    scanf("%d", &N);

    for (y = 1; y <= N; y++)
        for (x = 1; x <= N; x++)
            scanf("%d", &map[y][x]);
    nth = 0;
    for (y = 1; y <= N; y++)
        for (x = 1; x <= N; x++)
            if (map[y][x] == 1)
                dfs(y, x, --nth);
    printf("%d", bfs(-nth));
    /*printf("\n");
    for (y = 1; y <= N; y++) {
        for (x = 1; x <= N; x++)
            printf("%3d ", map[y][x]);
        printf("\n");
    }*/
}