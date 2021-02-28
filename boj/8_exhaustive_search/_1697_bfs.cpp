#include <cstdio>
#include <queue>

int N, K;

int bfs(int N) {
    int ans = abs(K - N);

    std::queue<int> q;
    q.push(N);
    while (!q.empty()) {
        
    }
    
}

int main() {
    scanf("%d %d", &N, &K);
    printf("%d", bfs(N));
}