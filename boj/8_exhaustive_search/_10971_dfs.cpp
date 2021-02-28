#include <cstdio>
#include <algorithm>
#define INF 0x7fffffff

int W[10][10], N;
bool visited[10];

int tsp(int v, int ith) {
    visited[v] = true;
    int dist = INF, tmp;

    if (ith == N - 1)
        dist = W[v][0] ? W[v][0] : INF;
    else
        for (int w = 0; w < N; w++)
            if (!visited[w] && W[v][w] && (tmp = tsp(w, ith + 1)) != INF)
                dist = std::min(dist, W[v][w] + tmp);
    
    visited[v] = false;
    return dist;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &W[i][j]);
    printf("%d", tsp(0, 0));
}