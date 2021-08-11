#include <cstdio>
#include <queue>
using namespace std;

int N, M;
int map[102][102];
int dist[102][102];

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    queue<pair<int, int>> q;

    int dy[4] = { -1, 0, 0, 1 }, dx[4] = { 0, -1, 1, 0 };
    int ny, nx;

    q.push({ 1, 1 }), map[1][1] = 0;
    dist[1][1] = 1;
    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            ny = y + dy[i], nx = x + dx[i];
            if (map[ny][nx]) {
                q.push({ ny, nx }), map[ny][nx] = 0;
                dist[ny][nx] = dist[y][x] + 1;
            }
        }
    }
    printf("%d", dist[N][M]);
}