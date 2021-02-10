// - 간단한 구조체가 필요할 때는 tuple을 사용.
//     std::make_tuple(...) 또는 {...},  std::get<1>(tu) = 2.
// - 좌표 혼동.
//     i -> y, j -> x 통일! 지도상으로 그릴 때는 앞으로 i, j 말고 y, x로 해보자. map[y][x];

#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;

int map[1002][1002];
int dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1};

int bfs(int N, int M) {
    int y, x, time = 0;
    queue<tuple<int, int, int>> q;
    tuple<int, int, int> t;

    for (y = 1; y <= N; y++)
        for (x = 1; x <= M; x++)
            if (map[y][x] == 1)
                q.push({y, x, time}), map[y][x] = 0;
    while (!q.empty()) {
        t = q.front(), q.pop();
        y = get<0>(t), x = get<1>(t), time = get<2>(t);

        if (map[y][x])
            continue;
        map[y][x] = 1;
        for (int i = 0; i < 4; i++)
            q.push({y + dy[i], x + dx[i], time + 1});
    }
    for (y = 1; y <= N; y++)
        for (x = 1; x <= M; x++)
            if (!map[y][x])
                return -1;
    return time - 1;
}

int main() {
    int N, M, y, x, ans;
    scanf("%d %d", &M, &N);
    for (y = 1; y <= N; y++)  // y 다음에 x!
        for (x = 1; x <= M; x++)
            scanf("%d", &map[y][x]);
    for (x = 0; x <= M + 1; x++)
        map[0][x] = map[N + 1][x] = -1;
    for (y = 0; y <= N + 1; y++)
        map[y][0] = map[y][M + 1] = -1;
    
    printf("%d", bfs(N, M));
}