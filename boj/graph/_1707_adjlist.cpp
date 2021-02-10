#include <cstdio>
#define MAX_VERTICES 20000

struct Node { int vertex; Node *next; };

Node *nodes[MAX_VERTICES + 1];
short int visited[MAX_VERTICES + 1];

void insert(int v, int w) {
    Node *node = new Node;
    node->vertex = w, node->next = nodes[v];
    nodes[v] = node;
}
bool dfs(int v, short int color) {
    visited[v] = color;
    for (Node *node = nodes[v]; node; node = node->next) {
        int w = node->vertex;
        if (visited[w] == color)
            return false;
        if (!visited[w] && !dfs(w, -color))
            return false;
    }
    return true;
}

int main() {
    int K, V, E, i, j;
    scanf("%d", &K);
    while (K--) {
        scanf("%d %d", &V, &E);
        while (E--) {
            scanf("%d %d", &i, &j);
            insert(i, j), insert(j, i);
        }
        bool is_bipart = true;
        for (i = 1; i <= V; i++) {
            if (!visited[i] && !dfs(i, 1)) {
                is_bipart = false;
                break;
            }
        }
        puts(is_bipart ? "YES" : "NO");
        for (i = 1; i <= V; i++) {
            for (Node *node = nodes[i], *tmp; node; node = tmp) {
                tmp = node->next;
                delete node;
            }
            nodes[i] = nullptr;
            visited[i] = 0;
        }
    }
}