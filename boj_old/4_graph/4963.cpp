#include <cstdio>
#define MAX_N 50

bool map[MAX_N + 2][MAX_N + 2];

bool dfs(int i, int j) {
    if (!map[i][j])
        return false;
    map[i][j] = false;
    dfs(i - 1, j), dfs(i + 1, j), dfs(i, j - 1), dfs(i, j + 1);
    dfs(i - 1, j - 1), dfs(i - 1, j + 1), dfs(i + 1, j - 1), dfs(i + 1, j + 1);
    return true;
}

int main() {
    int w, h, i, j, cnt;
    
    while (true) {
        scanf("%d %d", &w, &h);
        if (!(w || h))
            break;
        for (i = 1; i <= h; i++)  // row
            for (j = 1; j <= w; j++)  // col
                scanf("%d", &map[i][j]);
        cnt = 0;
        for (i = 1; i <= h; i++)
            for (j = 1; j <= w; j++)
                cnt += dfs(i, j);
        printf("%d\n", cnt);
    }
}