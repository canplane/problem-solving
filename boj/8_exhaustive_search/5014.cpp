/* bfs는 큐에 넣을 때 방문 처리해야 한다고!!! */

#include <cstdio>
#include <queue>
using namespace std;

bool visit[1000001];

int main() {
    int F, S, G, U, D;
    scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);

    int ans = 0, seg = 1;
    queue<int> q;
    visit[S] = true, q.push(S);
    while (!q.empty()) {
        int next_seg = 0;
        while (seg--) {
            S = q.front(), q.pop();
            if (S == G) {
                printf("%d", ans);
                return 0;
            }
            if (U > 0 && S + U <= F && !visit[S + U])
                visit[S + U] = true, q.push(S + U), next_seg++;
            if (D > 0 && S - D >= 1 && !visit[S - D])
                visit[S - D] = true, q.push(S - D), next_seg++;
        }
        ans++, seg = next_seg;
    }
    printf("use the stairs");
}