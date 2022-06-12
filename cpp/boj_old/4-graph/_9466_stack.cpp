#include <cstdio>
#include <stack>
#define MAX_N 100000

int next[MAX_N + 1], group[MAX_N + 1];

std::stack<int> s;
bool visited[MAX_N + 1];

int f(int v) {
    int leader;
    while (true) {
        if (group[v]) {
            leader = -1;
            break;
        }
        if (visited[v]) {
            leader = v;
            break;
        }
        visited[v] = true, s.push(v);
        v = next[v];
    }
    while (!s.empty()) {
        v = s.top(), s.pop(), visited[v] = false;
        group[v] = leader;
        if (v == leader)
            leader = -1;
    }
    return group[v] == -1;
}

int main() {
    int T, n, i, ans;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (i = 1; i <= n; i++)
            scanf("%d", &next[i]);
        ans = 0;
        for (i = 1; i <= n; i++)
            ans += f(i);
        printf("%d\n", ans);
        for (i = 1; i <= n; i++)
            group[i] = 0;
    }
}