#include <cstdio>
#include <algorithm>
#define MAX 0x7fffffff

int map[100][100], N, M;
bool visit[100][100];

int dy[4] = { -1, 1, 0, 0 }, dx[4] = { 0, 0, -1, 1 };

int dfs(int y, int x) {
    if (y == N - 1 && x == M - 1)
        return 0;
    
    visit[y][x] = true;
    int ret = MAX;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M || visit[ny][nx])
            continue;
        ret = std::min(ret, dfs(ny, nx));
    }
    visit[y][x] = false;

    return ret + (ret != MAX) * map[y][x];
}

int main() {
    scanf("%d %d", &M, &N);
    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++)
            scanf("%1d", &map[y][x]);
    printf("%d", dfs(0, 0));
}