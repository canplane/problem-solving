// 주어지는 그래프에서 위상 정렬이 가능한 정점의 수를 찾는 문제랑 다를 게 없다고 함.

#include <cstdio>
#define MAX_N 100000

int next[MAX_N + 1], group[MAX_N + 1];

bool visited[MAX_N + 1];

int f(int v) {
    if (group[v])
        return -1;
    if (visited[v])
        return v;
    visited[v] = true;
    group[v] = f(next[v]);
    visited[v] = false;
    return (group[v] == v)? -1 : group[v];
}

int main() {
    int T, n, i, ans;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (i = 1; i <= n; i++) {
            scanf("%d", &next[i]);
            group[i] = 0;
        }
        ans = 0;
        for (i = 1; i <= n; i++) {
            f(i);
            ans += (group[i] == -1);
        }
        printf("%d\n", ans);
    }
}