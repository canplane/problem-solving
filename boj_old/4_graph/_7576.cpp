// 좌표가 상당히 헷갈린다. y를 세로 축, x를 가로 축으로 해서 유지할 것.

#include <cstdio>
#include <queue>

int map[1002][1002];

int bfs(int N, int M) {
    int row, col, time = 0;
    std::queue<int> q;

    for (row = 1; row <= N; row++)
        for (col = 1; col <= M; col++)
            if (map[row][col] == 1)
                q.push(row), q.push(col), q.push(time), map[row][col] = 0;
    while (!q.empty()) {
        (row = q.front(), q.pop()), (col = q.front(), q.pop()), (time = q.front(), q.pop());
        if (map[row][col])
            continue;
        map[row][col] = 1;
        q.push(row - 1), q.push(col), q.push(time + 1);
        q.push(row + 1), q.push(col), q.push(time + 1);
        q.push(row), q.push(col - 1), q.push(time + 1);
        q.push(row), q.push(col + 1), q.push(time + 1);
    }
    for (row = 1; row <= N; row++)
        for (col = 1; col <= M; col++)
            if (!map[row][col])
                return -1;
    return time - 1;  // while 문 바깥으로 나왔다는 것은 이전에 큐에 들어간 것이 모두 걸러졌다는 것이므로 -1.
}

int main() {
    int N, M, row, col, ans;
    scanf("%d %d", &M, &N);
    for (row = 1; row <= N; row++)
        for (col = 1; col <= M; col++)
            scanf("%d", &map[row][col]);
    for (col = 0; col <= M + 1; col++)
        map[0][col] = map[N + 1][col] = -1;
    for (row = 0; row <= N + 1; row++)
        map[row][0] = map[row][M + 1] = -1;

    printf("%d", bfs(N, M));
}