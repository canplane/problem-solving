// int (&cur)[3][3] = q.front();

// visited가 없으므로 -1을 표시할 방법이 없다.

#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
    int puz[3][3];
};

int main() {
    Node node;
    for (int y = 0; y < 3; y++)
        for (int x = 0; x < 3; x++)
            scanf("%d", &node.puz[y][x]);
    
    int ans = 0, seg = 1, next_seg;
    queue<Node> q;
    q.push(node);
    while (!q.empty()) {
        int next_seg;
        int blank_y, blank_x;

        while (seg--) {
            node = q.front();
            for (int y = 0; y < 3; y++)
                for (int x = 0; x < 3; x++)
                    if (!node.puz[y][x])
                        blank_y = y, blank_x = x;
            q.pop();

            bool match = true;
            for (int i = 0; i < 9; i++)
                if (node.puz[i / 3][i % 3] != (i + 1) % 9) {
                    match = false;
                    break;
                }
            if (match)
                goto outer;

            if (blank_y - 1 >= 0) {
                swap(node.puz[blank_y - 1][blank_x], node.puz[blank_y][blank_x]);
                q.push(node), next_seg++;
                swap(node.puz[blank_y - 1][blank_x], node.puz[blank_y][blank_x]);
            }
            if (blank_y + 1 < 3) {
                swap(node.puz[blank_y + 1][blank_x], node.puz[blank_y][blank_x]);
                q.push(node), next_seg++;
                swap(node.puz[blank_y + 1][blank_x], node.puz[blank_y][blank_x]);
            }
            if (blank_x - 1 >= 0) {
                swap(node.puz[blank_y][blank_x - 1], node.puz[blank_y][blank_x]);
                q.push(node), next_seg++;
                swap(node.puz[blank_y][blank_x - 1], node.puz[blank_y][blank_x]);
            }
            if (blank_x + 1 < 3) {
                swap(node.puz[blank_y][blank_x + 1], node.puz[blank_y][blank_x]);
                q.push(node), next_seg++;
                swap(node.puz[blank_y][blank_x + 1], node.puz[blank_y][blank_x]);
            }
        }
        ans++, seg = next_seg;
    }
    outer:;
    printf("%d", ans);
}