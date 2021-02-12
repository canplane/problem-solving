/**
 *  이 때까지 푼 것 중에 왜 안 되는지 제일 이해 안 되던 문제 아닐까...
 *  min 넣어서 일단 fail 났던 것 성공시키긴 했는데, 다시 짜보고 정확히 이해하자.
 */

#include <cstdio>
#include <queue>
#include <tuple>
#include <climits>
#include <algorithm>
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

    int min_d = INT_MAX;

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
            if (map[y][x] != nth)
                min_d = min(min_d, dist[y][x] + d - 1);
            continue;
        }
        map[y][x] = nth, dist[y][x] = d;
        for (int i = 0; i < 4; i++)
            q.push({y + dy[i], x + dx[i], nth, d + 1});
    }
    return (min_d == INT_MAX) ? -1 : min_d;
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