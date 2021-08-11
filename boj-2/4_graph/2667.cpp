#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int map[27][27];

int dy[] = { -1, 1, 0, 0 }, dx[] = { 0, 0, -1, 1 };

int dfs(int y, int x) {
    int cnt = 1;
    map[y][x] = 0;

    int ny, nx;
    for (int i = 0; i < 4; i++) {
        ny = y + dy[i], nx = x + dx[i];
        if (map[ny][nx]) {
            cnt += dfs(ny, nx);
        }
    }
    return cnt;
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    vector<int> ans;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (map[i][j]) {
                ans.push_back(dfs(i, j));
            }
        }
    }
    sort(ans.begin(), ans.end());

    printf("%lu\n", ans.size());
    for (int e : ans) {
        printf("%d\n", e);
    }
    
}