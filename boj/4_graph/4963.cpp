#include <cstdio>

int w, h;
int map[52][52];
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 }, dx[8] ={ -1, 0, 1, -1, 1, -1, 0, 1 };

void dfs(int y, int x) {
    map[y][x] = 0;

    int ny, nx;
    for (int i = 0; i < 8; i++) {
        ny = y + dy[i], nx = x + dx[i];
        if (map[ny][nx]) {
            dfs(ny, nx);
        }
    }
}

int main() {
    while (true) {
        scanf("%d %d", &w, &h);
        if (!w && !h) {
            return 0;
        }

        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                scanf("%d", &map[i][j]);
            }
        }

        int ans = 0;
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                if (map[i][j]) {
                    ++ans, dfs(i, j);
                }
            }
        }
        printf("%d\n", ans);
    }
}