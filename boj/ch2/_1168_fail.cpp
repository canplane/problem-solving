#include <cstdio>
#include <queue>

int main()
{
    int N, K, i, j;
    scanf("%d %d", &N, &K);

    std::queue<int> q;
    for (i = 1; i <= N; i++) q.push(i);
    
    printf("<");
    for (i = 1; i < N; i++) {
        for (j = 1; j < K; j++) q.push(q.front()), q.pop();
        printf("%d, ", q.front()), q.pop();
    }
    printf("%d>", q.front()), q.pop();
}