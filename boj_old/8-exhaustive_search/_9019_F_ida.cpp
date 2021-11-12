/* 시간 초과 */

#include <cstdio>
#include <cstring>

char buf[10000];
bool visit[10000];

bool ida(int X, int B, int dep, int max_dep) {
    if (X == B) {
        buf[dep] = '\0';
        return true;
    }
    if (dep == max_dep)
        return false;
    
    visit[X] = true;
    int Y;

    buf[dep] = 'D', Y = (2 * X) % 10000; 
    if (!visit[Y] && ida(Y, B, dep + 1, max_dep))
        return true;
    buf[dep] = 'S', Y = (X + 9999) % 10000;
    if (!visit[Y] && ida(Y, B, dep + 1, max_dep))
        return true;
    buf[dep] = 'L', Y = (X * 10) % 10000 + (X / 1000) % 10;
    if (!visit[Y] && ida(Y, B, dep + 1, max_dep))
        return true;
    buf[dep] = 'R', Y = (X / 10) + (X % 10) * 1000;
    if (!visit[Y] && ida(Y, B, dep + 1, max_dep))
        return true;

    visit[X] = false;
    return false;
}

int main() {
    int T, A, B;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &A, &B);
        for (int i = 0; ; i++)
            if (ida(A, B, 0, i)) {
                memset(visit, 0, sizeof(visit));
                printf("%s\n", buf);
                break;
            }
    }
}