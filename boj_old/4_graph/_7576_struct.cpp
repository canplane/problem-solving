#include <cstdio>
#include <queue>
using namespace std;

int map[1002][1002];
int dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1};
struct Point { int y, x, time; };

int bfs(int N, int M) {
    int y, x, time = 0;
    queue<Point> q;
    Point p;
    
    for (y = 1; y <= N; y++)
        for (x = 1; x <= M; x++)
            if (map[y][x] == 1)
                q.push({y, x, time}), map[y][x] = 0;
    while (!q.empty()) {
        p = q.front(), q.pop();
        y = p.y, x = p.x, time = p.time;
        if (map[y][x])
            continue;
        map[y][x] = 1;
        for (int i = 0; i < 4; i++)
            q.push({y + dy[i], x + dx[i], time + 1});
    }
    for (y = 1; y <= N; y++)
        for (x = 1; x <= M; x++)
            if (!map[y][x])
                return -1;
    return time - 1;
}

int main() {
    int N, M, y, x, ans;
    scanf("%d %d", &M, &N);
    for (y = 1; y <= N; y++)
        for (x = 1; x <= M; x++)
            scanf("%d", &map[y][x]);
    for (x = 0; x <= M + 1; x++)
        map[0][x] = map[N + 1][x] = -1;
    for (y = 0; y <= N + 1; y++)
        map[y][0] = map[y][M + 1] = -1;
    
    printf("%d", bfs(N, M));
}