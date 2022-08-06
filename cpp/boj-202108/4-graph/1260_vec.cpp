#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<int> graph[1001];
int N, M, V;

bool visit[1001];

void dfs(int v) {
    visit[v] = true;
    cout << v << " ";
    for (auto w : graph[v]) {
        if (!visit[w]) {
            dfs(w);
        }
    }
}

// queue 넣을 때 visit!
void bfs(int v) {
    queue<int> q;
    visit[v] = true, q.push(v);
    while (!q.empty()) {
        v = q.front(), q.pop();
        cout << v << " ";
        for (auto x : graph[v]) {
            if (!visit[x]) {
                visit[x] = true, q.push(x);
            }
        }
    }
}

int main() {
    cin >> N >> M >> V;

    int x, y;    
    while (M--) {
        cin >> x >> y;
        graph[x].push_back(y), graph[y].push_back(x); 
    }
    
    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    
    dfs(V);
    cout << endl;

    memset(visit, 0, sizeof(visit));
    bfs(V);
    cout << endl;
}