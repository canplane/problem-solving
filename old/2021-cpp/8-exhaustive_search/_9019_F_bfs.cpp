#include <cstdio>
#include <string>
#include <queue>
#include <utility>
using namespace std;

void bfs(int A, int B) {
    queue<pair<int, string>> q;
    bool visit[10000] = {};

    q.push({ A, "" });
    while (!q.empty()) {
        auto [X, s] = q.front();
        q.pop();
        visit[X] = true;
        if (X == B) {
            printf("%s\n", s.c_str());
            return;
        }

        int Y, idx;
        s.resize((idx = s.size()) + 1);
        s[idx] = 'D', Y = (2 * X) % 10000;
        if (!visit[Y])
            q.push({ Y, s });
        s[idx] = 'S', Y = (X + 9999) % 10000;
        if (!visit[Y])
            q.push({ Y, s });  // 여기서 visited 검사 안 해서 시간 초과.
        s[idx] = 'L', Y = (X * 10) % 10000 + (X / 1000) % 10;
        if (!visit[Y])
            q.push({ Y, s });
        s[idx] = 'R', Y = (X / 10) + (X % 10) * 1000;
        if (!visit[Y])
            q.push({ Y, s });
    }
}

int main() {
    int T, A, B;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &A, &B);
        bfs(A, B);
    }
}