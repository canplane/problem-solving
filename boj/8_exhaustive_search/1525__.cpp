/* A* algorithm */

#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

int goal[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8 }, cur[3][3];

struct Node {
    int arr[3][3];
    double f, g;
    bool operator<(const Node& a) const {
        return f < a.f;
    }
};

double score(int cur[][3]) {
    double h = 0;
    for (int y1 = 0; y1 < 3; y1++)
        for (int x1 = 0; x1 < 3; x1++) {
            int y2 = (cur[y1][x1] - 1) / 3, x2 = (cur[y1][x1] - 1) % 3;
            h += sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2));
        }
    return h;
}

int main() {
    for (int y = 0; y < 3; y++)
        for (int x = 0; x < 3; x++)
            scanf("%d", &cur[y][x]);
    
    priority_queue<Node> pq;
    Node node;
    node.arr = { .arr = cur, .f = score(), q };
    pq.push(node);
    while () {
        node = 
    }
}