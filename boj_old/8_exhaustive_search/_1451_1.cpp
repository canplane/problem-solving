#include <cstdio>
#include <algorithm>
using namespace std;

int map[101][101], N, M;

long long sum(int Ax, int Ay, int Bx, int By) {  // get sum
    return map[By][Bx] - map[By][Ax] - map[Ay][Bx] + map[Ay][Ax];
}

int main() {
    scanf("%d %d", &N, &M);
    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++) {
            scanf("%1d", &map[y + 1][x + 1]);
            map[y + 1][x + 1] += map[y + 1][x] + map[y][x + 1] - map[y][x];  // set sum
        }

    long long ans = 0;
    for (int y1 = 1; y1 < N; y1++)
        for (int y2 = y1 + 1; y2 < N; y2++)
            ans = max(ans, sum(0, 0, M, y1) * sum(0, y1, M, y2) * sum(0, y2, M, N));
    for (int x1 = 1; x1 < M; x1++)
        for (int x2 = x1 + 1; x2 < M; x2++)
            ans = max(ans, sum(0, 0, x1, N) * sum(x1, 0, x2, N) * sum(x2, 0, M, N));

    for (int y = 1; y < N; y++)
        for (int x = 1; x < M; x++) {
            ans = max(ans, sum(0, 0, M, y) * sum(0, y, x, N) * sum(x, y, M, N));
            ans = max(ans, sum(0, 0, x, y) * sum(x, 0, M, y) * sum(0, y, M, N));

            ans = max(ans, sum(0, 0, x, N) * sum(x, 0, M, y) * sum(x, y, M, N));
            ans = max(ans, sum(0, 0, x, y) * sum(0, y, x, N) * sum(x, 0, M, N));
        }
    printf("%lld", ans);
}