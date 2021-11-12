#include <cstdio>

int maze[102][102], dist[102][102], N, M;

int dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1};

void dfs(int y, int x, int d) {
    if (!maze[y][x])
        return;
    if (dist[y][x] && dist[y][x] <= d)
        return;
    dist[y][x] = d;
    for (int i = 0; i < 4; i++)
        dfs(y + dy[i], x + dx[i], d + 1);
}

int main() {
    int y, x;
    scanf("%d %d", &N, &M);
    for (y = 1; y <= N; y++)
        for (x = 1; x <= M; x++)
            scanf("%1d", &maze[y][x]);
    dfs(1, 1, 1);
    printf("%d", dist[N][M]);
}