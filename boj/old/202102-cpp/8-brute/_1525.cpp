#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

map<int, bool> visit;

int arr_to_int(int arr[][3]) {
    int d = 0;
    for (int i = 0; i < 9; i++)
        d = 10 * d + arr[i / 3][i % 3];
    return d;
}
void int_to_arr(int d, int arr[][3]) {  // 운이 좋아서 맞았네. 뒤부터 정리했으니. 맨 앞자리가 0이면 망하는 것.
    for (int i = 8; i >= 0; i--) {
        arr[i / 3][i % 3] = d % 10;
        d /= 10;
    }
}

int main() {
    int puz[3][3], d;
    for (int y = 0; y < 3; y++)
        for (int x = 0; x < 3; x++)
            scanf("%d", &puz[y][x]);
    
    int ans = 0, seg = 1, next_seg;
    queue<int> q;
    visit[d = arr_to_int(puz)] = true, q.push(d);
    while (!q.empty()) {
        int next_seg = 0;
        int blank_y, blank_x;

        while (seg--) {
            int_to_arr(d = q.front(), puz), q.pop();
            if (d == 123456780) {
                printf("%d", ans);
                return 0;
            }

            for (int y = 0; y < 3; y++)
                for (int x = 0; x < 3; x++)
                    if (!puz[y][x])
                        blank_y = y, blank_x = x;

            if (blank_y - 1 >= 0) {
                swap(puz[blank_y - 1][blank_x], puz[blank_y][blank_x]);
                if (!visit[d = arr_to_int(puz)])
                    visit[d] = true, q.push(d), next_seg++;
                swap(puz[blank_y - 1][blank_x], puz[blank_y][blank_x]);
            }
            if (blank_y + 1 < 3) {
                swap(puz[blank_y + 1][blank_x], puz[blank_y][blank_x]);
                if (!visit[d = arr_to_int(puz)])
                    visit[d] = true, q.push(d), next_seg++;
                swap(puz[blank_y + 1][blank_x], puz[blank_y][blank_x]);
            }
            if (blank_x - 1 >= 0) {
                swap(puz[blank_y][blank_x - 1], puz[blank_y][blank_x]);
                if (!visit[d = arr_to_int(puz)])
                    visit[d] = true, q.push(d), next_seg++;
                swap(puz[blank_y][blank_x - 1], puz[blank_y][blank_x]);
            }
            if (blank_x + 1 < 3) {
                swap(puz[blank_y][blank_x + 1], puz[blank_y][blank_x]);
                if (!visit[d = arr_to_int(puz)])
                    visit[d] = true, q.push(d), next_seg++;
                swap(puz[blank_y][blank_x + 1], puz[blank_y][blank_x]);
            }
        }
        ans++, seg = next_seg;
    }
    printf("%d", -1);
}