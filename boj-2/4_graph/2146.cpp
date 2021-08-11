#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

#define INF 0x7fffffff

int N;
int map[102][102], dist[102][102];

queue<pair<int, int> > q;

int dy[4] = { -1, 0, 0, 1 }, dx[4] = { 0, -1, 1, 0 };

void dfs(int y, int x, int nth) {
    map[y][x] = nth;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if (map[ny][nx] == 1) {
            dfs(ny, nx, nth);
        }
    }   
}

int main() {
    scanf("%d", &N);
    // 가장자리
    for (int i = 0; i <= N + 1; i++) {
        map[i][0] = map[i][N + 1] = -1;
        map[0][i] = map[N + 1][i] = -1;
    }
    // 지도 입력
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 1) {
                q.push({ i, j });
            }
        }
    }

    // 구획 나누기
    int nth = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (map[i][j] == 1) {
                dfs(i, j, ++nth);
            }
        }
    }
    
    int ans = INF;
    int cycle = 0;
    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        if (cycle != dist[y][x]) {
            if (ans != INF) {
                break;
            }
            cycle = dist[y][x];
        }

        int ny, nx;
        for (int i = 0; i < 4; i++) {
            ny = y + dy[i], nx = x + dx[i];
            if (map[ny][nx] > 1 && map[ny][nx] != map[y][x]) {
                ans = min(ans, dist[y][x] + dist[ny][nx]);
            }
            if (map[ny][nx] == 0) {
                q.push({ ny, nx }), map[ny][nx] = map[y][x];
                dist[ny][nx] = dist[y][x] + 1;
            }
        }
    }

    /*for (int i = 0; i <= N + 1; i++) {
        for (int j = 0; j <= N + 1; j++) {
            printf("%3d", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i <= N + 1; i++) {
        for (int j = 0; j <= N + 1; j++) {
            printf("%3d", dist[i][j]);
        }
        printf("\n");
    }
    printf("\n");*/
    printf("%d", ans);
}