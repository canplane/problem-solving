#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX_N 25

int map[MAX_N + 2][MAX_N + 2];  // 반대쪽에도 패딩이 있어야 한다! MAX_N + 1이 아님!

int dfs(int i, int j) {
    if (!map[i][j])
        return 0;
    map[i][j] = 0;
    return 1 + dfs(i - 1, j) + dfs(i + 1, j) + dfs(i, j - 1) + dfs(i, j + 1);
}

int main() {
    int N, i, j, tmp;
    std::vector<int> v;

    scanf("%d", &N);
    for (i = 1; i <= N; i++)
        for (j = 1; j <= N; j++)
            scanf("%1d", &map[i][j]);
    for (i = 1; i <= N; i++)
        for (j = 1; j <= N; j++)
            if ((tmp = dfs(i, j)))
                v.push_back(tmp);
    std::sort(v.begin(), v.end());

    printf("%lu\n", v.size());
    for (auto& d : v)
        printf("%d\n", d);
}