#include <cstdio>

bool map[2001][2001], visit[2001][2001];

int dy[4] = { -1, 1, 0, 0 }, dx[4] = { 0, 0, -1, 1 };

void dfs(int y, int x) {
    visit[y][x] = true;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny < 0 || ny >= 2001 || nx < 0 || nx >= 2001)
            continue;
        if (map[ny][nx] && !visit[ny][nx])
            dfs(ny, nx);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        x1 = 2 * x1 + 1000, y1 = 2 * y1 + 1000, x2 = 2 * x2 + 1000, y2 = 2 * y2 + 1000;  // 사각형 바로 우측에 사각형 있을 때를 방지
        for (int x = x1; x <= x2; x++)
            map[y1][x] = map[y2][x] = true;
        for (int y = y1; y <= y2; y++)
            map[y][x1] = map[y][x2] = true;
    }

    int ans = 0;
    if (map[1000][1000])  // 이거 아니라고 else로 ans++하면 안 된다! 사각형 다 그리고 올릴 필요는 없기 때문.
        dfs(1000, 1000);
    for (int y = 0; y < 2001; y++)
        for (int x = 0; x < 2001; x++)
            if (map[y][x] && !visit[y][x])
                ans++, dfs(y, x);
    printf("%d", ans);
}