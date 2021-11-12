#include <cstdio>
#include <queue>
#include <utility>  // pair
#include <algorithm>
using namespace std;

int N, M;  // 세로, 가로
int map[1002][1002];
int dist[1002][1002];

int dy[4] = { -1, 0, 0, 1 }, dx[4] = { 0, -1, 1, 0 };

queue<pair<int, int>> q;

int main() {
    scanf("%d %d", &M, &N);
    for (int i = 0; i <= N + 1; i++)
        map[i][0] = map[i][M + 1] = -1;
    for (int j = 0; j <= M + 1; j++)
        map[0][j] = map[N + 1][j] = -1;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%d", &map[i][j]);

            if (map[i][j] == 1) {
                q.push({ i, j }), map[i][j] = -1;
            }
        }
    }

    // bfs
    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        int ny, nx;
        for (int i = 0; i < 4; i++) {
            ny = y + dy[i], nx = x + dx[i];
            if (map[ny][nx] != -1) {
                q.push({ ny, nx }), map[ny][nx] = -1;
                dist[ny][nx] = dist[y][x] + 1;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (!map[i][j]) {
                ans = -1;
                goto outer;
            }
            ans = max(ans, dist[i][j]);
        }
    }
outer:
    printf("%d", ans);
}