/* 왜 메모리 초과 뜨는지 모르겠다. 이건 뭐지? */

#include <cstdio>
#include <queue>
#include <tuple>
#include <algorithm>
#include <climits>
using namespace std;

int map[102][102], dist[102][102], N;
int dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1};

void dfs(int y, int x, int domain) {
    map[y][x] = domain;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny == 0 || ny == N + 1 || nx == 0 || nx == N + 1)
            continue;
        if (map[ny][nx] != 1)
            continue;
        dfs(ny, nx, domain);
    }
}

void bfs() {
    queue<tuple<int, int, int, int>> q;
    tuple<int, int, int, int> t;
    int y, x;

    for (y = 1; y <= N; y++) {
        for (x = 1; x <= N; x++) {
            if (map[y][x] == 0)
                continue;
            q.push({y, x, map[y][x], 0});
        }
    }

    int min_d = INT_MAX, prev_d = 0;
    while (!q.empty()) {
        t = q.front(), q.pop();
        y = get<0>(t), x = get<1>(t), map[y][x] = get<2>(t), dist[y][x] = get<3>(t);

        if (prev_d != dist[y][x]) {
            if (min_d != INT_MAX)
                break;
            prev_d = dist[y][x];
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny == 0 || ny == N + 1 || nx == 0 || nx == N + 1)
                continue;
            //// 이 검사하는 부분을 queue에서 뺄 때 하면 오히려 메모리 초과가 안 일어난다. 반대여야 하는 게 아닌가?
            if (map[ny][nx] == map[y][x])
                continue;
            if (map[ny][nx]) {
                min_d = min(min_d, dist[ny][nx] + dist[y][x]);
                continue;
            }
            ////
            q.push({ny, nx, map[y][x], dist[y][x] + 1});
        }
    }

    printf("%d", min_d);
}

int main() {
    int y, x;
    scanf("%d", &N);
    for (y = 1; y <= N; y++) {
        for (x = 1; x <= N; x++) {
            scanf("%d", &map[y][x]);
        }
    }
    
    int domain = 0;
    for (y = 1; y <= N; y++) {
        for (x = 1; x <= N; x++) {
            if (map[y][x] != 1)
                continue;
            dfs(y, x, --domain);
        }
    }
    bfs();

    /*printf("\n");
    for (y = 1; y <= N; y++) {
        for (x = 1; x <= N; x++) {
            printf("%3d", map[y][x]);
        }
        printf("\n");
    }*/
}