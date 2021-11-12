/**
 *  재귀 함수가 넘쳐서 segmentation fault가 나올 수도 있다.
 *  짜는데 한 시간 반 넘게 걸리는데... 심지어 틀렸네.
 *  실수는 왜 이렇게 많고...
 */

#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;

int map[102][102], dist[102][102], N;
int dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1};

void dfs(int y, int x, int nth) {
    if (map[y][x] != 1)
        return;
    map[y][x] = nth;
    for (int i = 0; i < 4; i++)
        dfs(y + dy[i], x + dx[i], nth);
}

int bfs() {
    int y, x, nth, d;
    queue<tuple<int, int, int, int>> q;
    tuple<int, int, int, int> t;

    for (y = 1; y <= N; y++)
        for (x = 1; x <= N; x++)
            if (map[y][x])
                q.push({y, x, map[y][x], 0}), map[y][x] = 0;
    while (!q.empty()) {
        t = q.front(), q.pop();
        y = get<0>(t), x = get<1>(t), nth = get<2>(t), d = get<3>(t);
        if (y == 0 || y == N + 1 || x == 0 || x == N + 1)
            continue;
        if (map[y][x]) {
            if (map[y][x] == nth)
                continue;
            return dist[y][x] + d - 1;
        }
        map[y][x] = nth, dist[y][x] = d;
        for (int i = 0; i < 4; i++)
            q.push({y + dy[i], x + dx[i], nth, d + 1});
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
    printf("%d", bfs());
}