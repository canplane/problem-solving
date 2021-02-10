#include <cstdio>
#include <stack>
#define MAX_N 100000

int next[MAX_N + 1], group[MAX_N + 1];

std::stack<int> s;
bool visited[MAX_N + 1];

void f(int v) {
    if (group[v])
        return;
    
    int leader;
    while (true) {
        s.push(v), visited[v] = true;
        if (group[next[v]]) {
            leader = -1;
            break;
        }
        if (visited[next[v]]) {
            leader = next[v];
            break;
        }
        v = next[v];
    }
    while (!s.empty()) {
        v = s.top(), s.pop(), visited[v] = false;
        group[v] = leader;
        if (v == leader)
            leader = -1;
    }
}

int main() {
    int T, n, ans;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &next[i]);
        ans = 0;
        for (int i = 1; i <= n; i++) {
            f(i);
            ans += (group[i] == -1);
        }
        printf("%d\n", ans);
        for (int i = 1; i <= n; i++)
            group[i] = 0;
    }
}